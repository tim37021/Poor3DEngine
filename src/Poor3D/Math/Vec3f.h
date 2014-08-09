#ifndef CORE_MATH_Vec3f_H_
#define CORE_MATH_Vec3f_H_

#include <cmath>

namespace Poor3D
{
	namespace Math
	{
		class Vec3f
		{
		public:
			float x, y, z;

			Vec3f(float _x, float _y, float _z): x(_x), y(_y), z(_z){}
			Vec3f(const Vec3f &copy)=default;

			const Vec3f operator+(const Vec3f &rhs) const
			{
				return Vec3f(x+rhs.x, y+rhs.y, z+rhs.z);
			}

			const Vec3f operator-(const Vec3f &rhs) const
			{
				return Vec3f(x-rhs.x, y-rhs.y, z-rhs.z);
			}

			const Vec3f operator*(const Vec3f &rhs) const
			{
				return Vec3f(x*rhs.x, y*rhs.y, z*rhs.z);
			}

			const Vec3f operator*(float factor) const
			{
				return Vec3f(x*factor, y*factor, z*factor);
			}

			float dot(const Vec3f &rhs) const 
			{
				return x*rhs.x + y*rhs.y + z*rhs.z;
			}

			float cross(const Vec3f &rhs) const 
			{
				return Vec3f(b*f-e*c, c*d-f*a, a*e-d*b);
			}

			float length() const
			{
				return sqrt(x*x+y*y+z*z);
			}

			void normalize()
			{
				float len = length();
				x/=len;
				y/=len;
				z/=len;
			}

		};

	}
}

#endif