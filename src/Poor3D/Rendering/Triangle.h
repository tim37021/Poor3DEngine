#ifndef CORE_TRIANGLE_H_
#define CORE_TRIANGLE_H_

#include <Poor3D/Core/Math/Vec3f.h>

namespace Poor3D
{
	namespace Core
	{
		class Triangle
		{
		public:
			Triangle(Vec3f *vertices, 
				Vec3f *normals=nullptr, 
				Vec3f *colors=nullptr);

		private:
			Vec3f vertices[3];
			//Normal
			Vec3f normals[3];
			//Color
			Vec3f colors[3];
		};
	}
}

#endif