#ifndef MATH_MAT4_H_
#define MATH_MAT4_H_

#include <Poor3D/Math/Math.h>
#include <Poor3D/Math/Vec3f.h>
#include <Poor3D/Math/Mat3.h>

namespace Poor3D
{
	namespace Math
	{
		struct Mat4
		{
			float data[4][4];

			Mat4()=default;

			void setIdentity()
			{
				data[0][0]=1.0f; data[0][1]=0.0f; data[0][2]=0.0f; data[0][3]=0.0f;
				data[1][0]=0.0f; data[1][1]=1.0f; data[1][2]=0.0f; data[1][3]=0.0f;
				data[2][0]=0.0f; data[2][1]=0.0f; data[2][2]=1.0f; data[2][3]=0.0f;
				data[3][0]=0.0f; data[3][1]=0.0f; data[3][2]=0.0f; data[3][3]=1.0f;
			}
			const Mat4 operator *(const Mat4 &rhs) const
			{
				Mat4 result;
				for(int i=0; i<4; i++)
					for(int j=0; j<4; j++)
						result.data[i][j]=data[i][0]*rhs.data[0][j]+data[i][1]*rhs.data[1][j]+
										  data[i][2]*rhs.data[2][j]+data[i][3]*rhs.data[3][j];
				return result;
			}

			//TODO: inv det
		};


		inline Mat4 TranslationMatrix(float x, float y, float z)
		{
			Mat4 result;
			result.setIdentity();
			result.data[0][3]=x; result.data[1][3]=y; result.data[2][3]=z;
			return result;
		}

		inline Mat4 ScaleMatrix(float x, float y, float z)
		{
			Mat4 result;
			result.setIdentity();
			result.data[0][0]=x; result.data[1][1]=y; result.data[2][2]=z;
			return result;
		}


		//TODO: make this smarter 
		inline void FindOrthoVec(const Vec3f &v, Vec3f &out1, Vec3f &out2)
		{	
			int i;
			int count=isZero(v.x)+isZero(v.y)+isZero(v.z);
			float sum=0.0f;
			float d[3]={v.x, v.y, v.z};
			int found;
			switch(count)
			{
				case 0:
					out1.x=1.0f;
					out1.y=1.0f;
					out1.z=-(v.x+v.y)/v.z;
					break;
				case 1:
				case 2:
					for(i=0; i<3; i++)
						if(isZero(d[i]))
							d[i]=1.0f;
						else
							d[i]=0.0f;
					out1.x=d[0]; out1.y=d[1]; out1.z=d[2];
					break;
				default:
					out1.x=0.0f; out1.y=0.0f; out1.z=0.0f;
			}

			out2 = v.cross(out1);
		}

		inline Mat4 RotationMatrix(float angle, const Vec3f &dir)
		{
			Vec3f u, v, w=dir;
			FindOrthoVec(w, u, v);
			const Mat3 &uvwMat = Mat3(u, v, w);
			const Mat3 result3x3=uvwMat*RotationMatrixByZ(angle)*uvwMat.inv();
			
			Mat4 result;
			result.data[0][0]=result3x3.data[0][0]; result.data[0][1]=result3x3.data[0][1]; result.data[0][2]=result3x3.data[0][2]; result.data[0][3]=0.0f;
			result.data[1][0]=result3x3.data[1][0]; result.data[1][1]=result3x3.data[1][1]; result.data[1][2]=result3x3.data[1][2]; result.data[1][3]=0.0f;
			result.data[2][0]=result3x3.data[2][0]; result.data[2][1]=result3x3.data[2][1]; result.data[2][2]=result3x3.data[2][2]; result.data[2][3]=0.0f;
			result.data[3][0]=0.0f; result.data[3][1]=0.0f; result.data[3][2]=0.0f; result.data[3][3]=1.0f;
			return result;
		}

	}

}


#endif
