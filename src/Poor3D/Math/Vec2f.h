#ifndef CORE_MATH_Vec2f_H_
#define CORE_MATH_Vec2f_H_

#include <cmath>

namespace Poor3D
{
	namespace Math
	{
		class Vec2f
		{
		public:
			float x, y;
			Vec2f(): x(0.0f), y(0.0f) {}
			Vec2f(float x_, float y_): x(x_), y(y_) {}
			
			float length() const
			{
				return sqrt(x*x+y*y);
			}

			void normalize()
			{
				float len=length();
				x/=len;
				y/=len;
			}

		};
	}
}

#endif