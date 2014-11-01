#ifndef RENDERING_VERTEX_H_
#define RENDERING_VERTEX_H_

#include <Poor3D/Math/Vec3f.h>
#include <Poor3D/Math/Vec2f.h>

namespace Poor3D
{
	namespace Rendering
	{
		struct Vertex
		{
			Poor3D::Math::Vec3f pos;
			Poor3D::Math::Vec2f texCoord;
			Poor3D::Math::Vec3f normal;
			Vertex()=default;
			Vertex(const Poor3D::Math::Vec3f &_p): pos(_p){}
			Vertex(const Poor3D::Math::Vec3f &_p,
					const Poor3D::Math::Vec2f &_t)
			: pos(_p), texCoord(_t){}
			Vertex(const Poor3D::Math::Vec3f &_p,
					const Poor3D::Math::Vec2f &_t,
					const Poor3D::Math::Vec3f &_n)
				: pos(_p), texCoord(_t), normal(_n){}
		};
	}
}

#endif