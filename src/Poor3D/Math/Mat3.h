#ifndef MATH_MAT3_H_
#define MATH_MAT3_H_

#include <Poor3D/Math/Vec3f.h>
#include <cmath>

namespace Poor3D
{
	namespace Math
	{
		class Mat3
		{
			public:
				float data[3][3];
				Mat3()=default;
				Mat3(const Vec3f &u, const Vec3f &v, const Vec3f &w)
				{
					data[0][0]=u.x; data[0][1]=u.y; data[0][2]=u.z;
					data[1][0]=v.x; data[1][1]=v.y; data[1][2]=v.z;
					data[2][0]=w.x; data[2][1]=w.y; data[2][2]=w.z;
				}

				const Mat3 operator*(const Mat3 &m) const
				{
					Mat3 result;
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<3; j++)
						{
							result.data[i][j]=0.0f;
							for(int k=0; k<3; k++)
								result.data[i][j]+=data[i][k]*m.data[k][j];
						}
					}
					return result;
				}

				const Vec3f operator*(const Vec3f &v) const
				{

					Vec3f result;
					result.x=data[0][0]*v.x+data[0][1]*v.y+data[0][2]*v.z;
					result.y=data[1][0]*v.x+data[1][1]*v.y+data[1][2]*v.z;
					result.z=data[2][0]*v.x+data[2][1]*v.y+data[2][2]*v.z;

					return result;		
				}

				const Mat3 operator*(float factor) const
				{

					Mat3 result;
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<3; j++)
						{
							result.data[i][j]=data[i][j]*factor;
						}
					}
					return result;	
				}

				const Mat3 operator+(const Mat3 &rhs) const
				{
					Mat3 result;
					for(int i=0; i<3; i++)
					{
						for(int j=0; j<3; j++)
						{
							result.data[i][j]=data[i][j]+rhs.data[i][j];
						}
					}
					return result;
				}

				void setIdentity()
				{
					data[0][0]=1.0f; data[0][1]=0.0f; data[0][2]=0.0f;
					data[1][0]=0.0f; data[1][1]=1.0f; data[1][2]=0.0f;
					data[2][0]=0.0f; data[2][1]=0.0f; data[2][2]=1.0f;
				}

				float det() const
				{
					return (data[0][0]*data[1][1]*data[2][2]+
							data[0][1]*data[1][2]*data[2][0]+
							data[1][0]*data[2][1]*data[0][2])
						-
						(data[2][0]*data[1][1]*data[0][2]+
						 data[0][1]*data[1][0]*data[2][2]+
						 data[0][0]*data[1][2]*data[2][1]);
				}
				Mat3 inv() const
				{
					float d=1.0f/det();
					Mat3 result;
					result.data[0][0]=d*(data[1][1]*data[2][2]-data[2][1]*data[1][2]);
					result.data[0][1]=d*(data[2][1]*data[0][2]-data[2][2]*data[0][1]);
					result.data[0][2]=d*(data[0][1]*data[1][2]-data[0][2]*data[1][1]);
					result.data[1][0]=d*(data[1][2]*data[2][0]-data[1][0]*data[2][2]);
					result.data[1][1]=d*(data[2][2]*data[0][0]-data[0][2]*data[2][0]);
					result.data[1][2]=d*(data[0][2]*data[1][0]-data[0][0]*data[1][2]);
					result.data[2][0]=d*(data[1][0]*data[2][1]-data[1][1]*data[2][0]);
					result.data[2][1]=d*(data[2][0]*data[0][1]-data[2][1]*data[0][0]);
					result.data[2][2]=d*(data[0][0]*data[1][1]-data[0][1]*data[1][0]);
					return result;
				}
		};


		inline Mat3 RotationMatrix3x3ByZ(float angle)
		{
			Mat3 result;
			result.data[0][0]=cos(angle); result.data[0][1]=-sin(angle); result.data[0][2]=0.0f;
			result.data[1][0]=sin(angle); result.data[1][1]=cos(angle);  result.data[1][2]=0.0f;
			result.data[2][0]=0.0f;	      result.data[2][1]=0.0f;	     result.data[2][2]=1.0f;

			return result;
		}

		//Rodrigues rotation formula
		inline Mat3 RotationMatrix3x3(float angle, const Math::Vec3f &dir)
		{
			Mat3 W; auto &m=W.data;
			m[0][0]=0.0f;	m[0][1]=-dir.z; m[0][2]=dir.y;
			m[1][0]=dir.z;	m[1][1]=0.0f;	m[1][2]=-dir.z;
			m[2][0]=-dir.y;	m[2][1]=dir.x;	m[2][2]=0.0f;

			Mat3 I; I.setIdentity();
			return I+W*sin(-angle)+(W*W)*(2.0f*sin(-angle/2.0f)*sin(-angle/2.0f));
		}
	}
}

#endif
