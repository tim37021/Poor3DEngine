#include <Poor3D/Scene/Camera.h>

using namespace Poor3D::Math;
using namespace Poor3D::Scene;

Camera::Camera(const Vec3f &p, const Vec3f &c, const Vec3f &u)
	: dirty(true), pos(p)
{
	dir=c-pos;
	dir.normalize();

	up=u;

	right=up.cross(dir);
	right.normalize();

	//we need to recalculate up vector so that three vector are perpendicular to each other
	up=dir.cross(right);
	up.normalize();


	calcMatrix();
}

void Camera::calcMatrix()
{
	Mat4 transMat=TranslationMatrix(-pos.x, -pos.y, -pos.z);
	Mat4 rotateMat;
	auto &rM=rotateMat.data;

	rM[0][0]=right.x; rM[0][1]=right.y; rM[0][2]=right.z; rM[0][3]=0.0f;
	rM[1][0]=up.x;		rM[1][1]=up.y;		rM[1][2]=up.z;		rM[1][3]=0.0f;
	rM[2][0]=dir.x;		rM[2][1]=dir.y; 	rM[2][2]=dir.z;		 rM[2][3]=0.0f;
	rM[3][0]=0.0f; rM[3][1]=0.0f; rM[3][2]=0.0f; rM[3][3]=1.0f;
	

	dirty=false;

	mat=rotateMat*transMat;
}
