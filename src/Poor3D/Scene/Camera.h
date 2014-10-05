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
				{dirty=true; pos=Poor3D::Math::Vec3f(x, y, z);}

			const Poor3D::Math::Mat4 &getMatrix()
			{
				if(dirty)
					calcMatrix();
				return mat;
			}
			const Poor3D::Math::Mat4 &getMatrix() const
				{return mat;}
		protected:
			bool dirty;
			Poor3D::Math::Vec3f pos;

			//These three are unit vector
			Poor3D::Math::Vec3f dir;
			Poor3D::Math::Vec3f up;
			Poor3D::Math::Vec3f right;
		private:
			Poor3D::Math::Mat4 mat;
			void calcMatrix();
		};
	}
}

#endif
