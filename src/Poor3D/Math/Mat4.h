#ifndef MATH_MAT4_H_
#define MATH_MAT4_H_

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


		Mat4 TranslationMatrix(float x, float y, float z);
		Mat4 ScaleMatrix(float x, float y, float z);
		void FindOrthoVec(const Vec3f &v, Vec3f &out1, Vec3f &out2);

		Mat4 RotationMatrix4x4ByX(float angle);
		Mat4 RotationMatrix4x4ByY(float angle);
		Mat4 RotationMatrix4x4ByZ(float angle);
		Mat4 RotationMatrix(float angle, const Vec3f &dir);

		Mat4 RotationMatrixEular(float x, float y, float z);
	
		Mat4 PerspectiveProjMatrix(float fov, float aspect, float zNear, float zFar);
	}
}


#endif
