#include <Poor3D/Core/Triangle.h>

using namespace Poor3D::Core;

Triangle::Triangle(Vec3f *v, Vec3f *n, Vec3f *c)
{
	for(int i=0; i<3; i++)
		vertices[i]=v[i];

	if(n)
		for(int i=0; i<3; i++)
			normals[i]=n[i];

	//TODO: color
}