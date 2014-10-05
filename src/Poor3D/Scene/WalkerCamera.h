#ifndef SCENE_WALKERCAMERA_H_
#define SCENE_WALKERCAMERA_H_

#include <Poor3D/Math/Vec3f.h>
#include <Poor3D/Scene/Camera.h>

namespace Poor3D
{
	namespace Scene
	{
		class WalkerCamera: public Camera
		{
		public:
			WalkerCamera(const Poor3D::Math::Vec3f &, const Poor3D::Math::Vec3f &, const Poor3D::Math::Vec3f &);
			void moveForward(float d);
			void turn(float angle);
		};
	}
}

#endif
