#ifndef CORE_TRIANGLE_H_
#define CORE_TRIANGLE_H_

#include <Poor3D/Math/Vec3f.h>

namespace Poor3D
{
	namespace Rendering
	{
		class Triangle
		{
		public:
			Triangle(Poor3D::Math::Vec3f *vertices, 
				Poor3D::Math::Vec3f *normals=nullptr, 
				Poor3D::Math::Vec3f *colors=nullptr);

		private:
			Poor3D::Math::Vec3f vertices[3];
			//Normal
			Poor3D::Math::Vec3f normals[3];
			//Color
			Poor3D::Math::Vec3f colors[3];
		};
	}
}

#endif