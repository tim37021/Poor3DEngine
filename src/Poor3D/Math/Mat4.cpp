#include <Poor3D/Math/Math.h>

using namespace Poor3D;

Math::Mat4 Math::TranslationMatrix(float x, float y, float z)
{
	Math::Mat4 result;
	result.setIdentity();
	result.data[0][3]=x; result.data[1][3]=y; result.data[2][3]=z;
	return result;
}

Math::Mat4 Math::ScaleMatrix(float x, float y, float z)
{
	Math::Mat4 result;
	result.setIdentity();
	result.data[0][0]=x; result.data[1][1]=y; result.data[2][2]=z;
	return result;
}


//TODO: make this smarter 
void Math::FindOrthoVec(const Math::Vec3f &v, Math::Vec3f &out1, Math::Vec3f &out2)
{	
	int i;
	int count=isZero(v.x)+isZero(v.y)+isZero(v.z);
	float d[3]={v.x, v.y, v.z};
	switch(count)
	{
		case 0:
			out1.x=1.0f;
			out1.y=1.0f;
			out1.z=-(v.x+v.y)/v.z;
			break;
		case 1:
		case 2:
			for(i=0; i<3; i++)
				if(isZero(d[i]))
					d[i]=1.0f;
				else
					d[i]=0.0f;
			out1.x=d[0]; out1.y=d[1]; out1.z=d[2];
			break;
		default:
			out1.x=0.0f; out1.y=0.0f; out1.z=0.0f;
	}

	out2 = v.cross(out1);
	out1.normalize();
	out2.normalize();
}

Math::Mat4 Math::RotationMatrix4x4ByX(float angle)
{
	Mat4 result;
	result.data[0][0]=1.0f; result.data[0][1]=0.0f; result.data[0][2]=0.0f; result.data[0][3]=0.0f;
	result.data[1][0]=0.0f; result.data[1][1]=cos(angle); result.data[1][2]=-sin(angle); result.data[1][3]=0.0f;
	result.data[2][0]=0.0f; result.data[2][1]=sin(angle); result.data[2][2]=cos(angle); result.data[2][3]=0.0f;
	result.data[3][0]=0.0f; result.data[3][1]=0.0f; result.data[3][2]=0.0f; result.data[3][3]=1.0f;
	return result;
}
Math::Mat4 Math::RotationMatrix4x4ByY(float angle)
{
	Mat4 result;
	result.data[0][0]=cos(angle); result.data[0][1]=0.0f; result.data[0][2]=sin(angle); result.data[0][3]=0.0f;
	result.data[1][0]=0.0f; result.data[1][1]=1.0f; result.data[1][2]=0.0f; result.data[1][3]=0.0f;
	result.data[2][0]=-sin(angle); result.data[2][1]=0; result.data[2][2]=cos(angle); result.data[2][3]=0.0f;
	result.data[3][0]=0.0f; result.data[3][1]=0.0f; result.data[3][2]=0.0f; result.data[3][3]=1.0f;
	return result;
}
Math::Mat4 Math::RotationMatrix4x4ByZ(float angle)
{
	Mat4 result;
	result.data[0][0]=cos(angle); result.data[0][1]=-sin(angle); result.data[0][2]=0.0f; result.data[0][3]=0.0f;
	result.data[1][0]=sin(angle); result.data[1][1]=cos(angle); result.data[1][2]=0.0f; result.data[1][3]=0.0f;
	result.data[2][0]=0.0f; result.data[2][1]=0.0f; result.data[2][2]=1.0f; result.data[2][3]=0.0f;
	result.data[3][0]=0.0f; result.data[3][1]=0.0f; result.data[3][2]=0.0f; result.data[3][3]=1.0f;
	return result;
}

//TODO: improve this
Math::Mat4 Math::RotationMatrix(float angle, const Math::Vec3f &dir)
{
	Math::Vec3f u, v, w=dir;
	FindOrthoVec(w, u, v);
	w.normalize();
	const Math::Mat3 &uvwMat = Mat3(u, v, w);
	const Math::Mat3 result3x3=uvwMat*RotationMatrix3x3ByZ(angle)*uvwMat.inv();

	Math::Mat4 result;
	result.data[0][0]=result3x3.data[0][0]; result.data[0][1]=result3x3.data[0][1]; result.data[0][2]=result3x3.data[0][2]; result.data[0][3]=0.0f;
	result.data[1][0]=result3x3.data[1][0]; result.data[1][1]=result3x3.data[1][1]; result.data[1][2]=result3x3.data[1][2]; result.data[1][3]=0.0f;
	result.data[2][0]=result3x3.data[2][0]; result.data[2][1]=result3x3.data[2][1]; result.data[2][2]=result3x3.data[2][2]; result.data[2][3]=0.0f;
	result.data[3][0]=0.0f; result.data[3][1]=0.0f; result.data[3][2]=0.0f; result.data[3][3]=1.0f;
	return result;
}

Math::Mat4 Math::RotationMatrixEular(float x, float y, float z)
{
	return RotationMatrix4x4ByX(x)*RotationMatrix4x4ByY(y)*RotationMatrix4x4ByZ(z);
}

Math::Mat4 Math::PerspectiveProjMatrix(float fov, float aspect, float zNear, float zFar)
{
	Math::Mat4 result;
	const float zRange=zNear - zFar;
	const float tanHalfFOV = tanf(fov / 2.0f);

	result.data[0][0]=1.0/(tanHalfFOV*aspect);
	result.data[0][1]=0.0f;
	result.data[0][2]=0.0f;
	result.data[0][3]=0.0f;

	result.data[1][0]=0.0f;
	result.data[1][1]=1.0f/tanHalfFOV;
	result.data[1][2]=0.0f;
	result.data[1][3]=0.0f;

	result.data[2][0]=0.0f;
	result.data[2][1]=0.0f;
	result.data[2][2]=(-zNear-zFar)/zRange;
	result.data[2][3]=2.0f*zFar*zNear/zRange;

	result.data[3][0]=0.0f;
	result.data[3][1]=0.0f;
	result.data[3][2]=1.0f;
	result.data[3][3]=0.0f;

	return result;
}
