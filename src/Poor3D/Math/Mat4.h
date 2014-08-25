#ifndef MATH_MAT4_H_
#define MATH_MAT4_H_

namespace Poor3D
{
	namespace Math
	{
		struct Mat4
		{
			float data[4][4];

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

		inline Mat4 RotationMatrix(float angle, float x, float y, float z)
		{

		}
	}

}


#endif