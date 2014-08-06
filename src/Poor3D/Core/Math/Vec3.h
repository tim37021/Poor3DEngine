#ifndef CORE_MATH_Vec3_H_
#define CORE_MATH_Vec3_H_

#include <cmath>

namespace Poor3D
{
	namespace Core
	{
		namespace Math
		{
			class Vec3
			{
			public:
				float x, y, z;

				Vec3(float _x, float _y, float _z): x(_x), y(_y), z(_z){}
				Vec3(const Vec3 &copy)=default;

				const Vec3 operator+(const Vec3 &rhs) const
				{
					return Vec3(x+rhs.x, y+rhs.y, z+rhs.z);
				}

				const Vec3 operator-(const Vec3 &rhs) const
				{
					return Vec3(x-rhs.x, y-rhs.y, z-rhs.z);
				}

				const Vec3 operator*(const Vec3 &rhs) const
				{
					return Vec3(x*rhs.x, y*rhs.y, z*rhs.z);
				}

				const Vec3 operator*(float factor) const
				{
					return Vec3(x*factor, y*factor, z*factor);
				}

				float dot(const Vec3 &rhs) const 
				{
					return x*rhs.x + y*rhs.y + z*rhs.z;
				}

				float cross(const Vec3 &rhs) const 
				{
					return Vec3(b*f-e*c, c*d-f*a, a*e-d*b);
				}

				float getLength() const
				{
					return sqrt(x*x+y*y+z*z);
				}

				void normalize()
				{
					float length = getLength();
					x/=length;
					y/=length;
					z/=length;
				}

			};
		}

	}
}

#endif