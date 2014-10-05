#ifndef SCENE_CAMERA_H_
#define SCENE_CAMERA_H_

#include <Poor3D/Math/Mat4.h>

namespace Poor3D
{
	namespace Scene
	{
		class Camera
		{
		public:
			Camera(const Poor3D::Math::Vec3f &pos, const Poor3D::Math::Vec3f &center, const Poor3D::Math::Vec3f &up);
			
			const Poor3D::Math::Vec3f &getPosition() const
				{return pos;}

			void setPosition(float x, float y, float z)
				{dirty=true; pos=Vec3f(x, y, z);}
			void setRotation(float x, float y, float z)
				{dirty=true; rotate=Vec3f(x, y, z);}

			const Poor3D::Math::Mat4 &getMatrix()
			{
				if(dirty)
					calcMatrix();
				return mat;
			}
			const Poor3D::Math::Mat4 &getMatrix() const
				{return mat;}
		protect:
			bool dirty;
			Poor3D::Math::Vec3f pos;
			Poor3D::Math::Vec3f rotate;
		private:
			Poor3D::Math::Mat4 mat;
			void calcMatrix(const Poor3D::Math::Vec3f &lookAt, const Poor3D::Math::Vec3f &up);
		};
	}
}

#endif
