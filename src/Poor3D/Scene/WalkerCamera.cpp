#include <Poor3D/Scene/WalkerCamera.h>
#include <Poor3D/Math/Vec3f.h>

using namespace Poor3D::Math;
using namespace Poor3D::Scene;

WalkerCamera::WalkerCamera(const Vec3f &p, const Vec3f &c, const Vec3f &u)
	: Camera(p, c, u)
{

}

#include <cstdio>

void WalkerCamera::moveForward(float d)
{
	pos+=dir*d;
	dirty=true;
	//fprintf(stderr, "%f %f %f\n", pos.x, pos.y, pos.z);
}

void WalkerCamera::turn(float angle)
{
	const Mat3 &rot=RotationMatrix3x3(angle, up);

	dir=rot*dir;
	dir.normalize();
	right=up.cross(dir);
	right.normalize();
	dirty=true;
}
