#ifndef MATH_TRANSMAT4_H_
#define MATH_TRANSMAT4_H_

#include <Poor3D/Math/Vec3.h>

namespace Poor3D
{
	namespace Math
	{
		class TransMat4
		{
		public:
			void setScale();
			void setRotation();
			void setTranslate();
			Mat4 getMatrix() const;
		private:
			Vec3 scale;
			Vec3 rotation;
			Vec3 translate;
		};
	}
}

#endif