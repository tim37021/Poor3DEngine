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
				: scale(1.0f, 1.0f, 1.0f), rotate(1.0f, 1.0f, 1.0f), translate(0.0f, 0.0f, 0.0f), dirty(true)
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
					rotationCache=RotationMatrixEular(rotate.x, rotate.y, rotate.z);
					const Mat4 &t=TranslationMatrix(translate.x, translate.y, translate.z);
					dirty=false;
					return cache=t*rotationCache*s;
				}
				return cache;
			}

			const Mat4 &getRotationMatrix()
			{
				if(dirty)
					getMatrix();
				return rotationCache;
			}
		private:
			Vec3f scale;
			Vec3f rotate;
			Vec3f translate;

			bool dirty;
			Mat4 cache;
			Mat4 rotationCache;
		};
	}
}

#endif
