#ifndef RENDERING_VERTEX_H_
#define RENDERING_VERTEX_H_

#include <Poor3D/Math/Vec3f.h>

namespace Poor3D
{
	namespace Rendering
	{
		struct Vertex
		{
			Poor3D::Math::Vec3f pos, normal, texCoord;
			Vertex()=default;
			Vertex(const Poor3D::Math::Vec3f &_p): pos(_p){}
			Vertex(const Poor3D::Math::Vec3f &_p,
					const Poor3D::Math::Vec3f &_n)
			: pos(_p), normal(_n){}
			Vertex(const Poor3D::Math::Vec3f &_p,
					const Poor3D::Math::Vec3f &_n,
					const Poor3D::Math::Vec3f &_t)
				: pos(_p), normal(_n), texCoord(_t){}
		};
	}
}

#endif