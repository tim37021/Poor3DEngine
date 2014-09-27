#ifndef MATH_TRANSMAT4_H_
#define MATH_TRANSMAT4_H_

#include <Poor3D/Math/Vec3f.h>
#include <Poor3D/Math/Mat4.h>

namespace Poor3D
{
	namespace Math
	{
		class TransMat4
		{
		public:
			TransMat4()
				: dirty(true), scale(1.0f, 1.0f, 1.0f), rotate(1.0f, 1.0f, 1.0f), translate(0.0f, 0.0f, 0.0f)
			{
			}

			void setScale(float x, float y, float z)
				{scale=Vec3f(x, y, z); dirty=true;}
			void setRotation(float x, float y, float z)
				{rotate=Vec3f(x, y, z); dirty=true;}
			void setTranslate(float x, float y, float z)
				{translate=Vec3f(x, y, z); dirty=true;}
			const Mat4 &getMatrix()
			{
				if(dirty){
					const Mat4 &s=ScaleMatrix(scale.x, scale.y, scale.z);
					const Mat4 &r=RotationMatrixEular(rotate.x, rotate.y, rotate.z);
					const Mat4 &t=TranslationMatrix(translate.x, translate.y, translate.z);
					dirty=false;
					return cache=t*r*s;
				}
				return cache;
			}
		private:
			Vec3f scale;
			Vec3f rotate;
			Vec3f translate;

			bool dirty;
			Mat4 cache;
		};
	}
}

#endif
