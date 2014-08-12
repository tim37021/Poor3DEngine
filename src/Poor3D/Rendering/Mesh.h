#ifndef CORE_MESH_H_
#define CORE_MESH_H_

#include <GLFW/glfw.h>
#include <Poor3D/Core/Triangle.h>
#include <vector>

namespace Poor3D
{
	namespace Core
	{
		class Mesh
		{
		public:
			Mesh(Geometric *geometric);
			~Mesh();

			void render();
		private:
			
			GLuint vbo;
		};
	}
}

#endif