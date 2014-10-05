#include <Poor3D/Scene/Camera.h>

using namespace Poor3D::Math;
using namespace Poor3D::Scene;

Camera::Camera(const Vec3f &p, const Vec3f &c, const Vec3f &u)
	: dirty(true), pos(p), rotate(0.0f, 0.0f, 0.0f)
{
	calcMatrix(c, u);
}

void Camera::calcMatrix(const Vec3f &c, const Vec3f &u)
{
	mat=TranslationMatrix(-pos.x, -pos.y, -pos.z);
	dirty=false;
}
