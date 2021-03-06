#ifndef CORE_MESH_H_
#define CORE_MESH_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Poor3D/Rendering/Vertex.h>
#include <vector>

namespace Poor3D
{
	namespace Rendering
	{
		class Mesh
		{
		public:
			Mesh(std::vector<Poor3D::Rendering::Vertex> &vertices,
				const std::vector<int> &indices);
			~Mesh();

			void render() const;
		private:
			GLuint vao;
			//vertex buffer object
			GLuint vbo;
			//index buffer object
			GLuint ibo;
			unsigned int indicesCount;

			void calcNormals(std::vector<Poor3D::Rendering::Vertex> &vertices, 
				const std::vector<int> &indices) const;
			void addVertices(std::vector<Poor3D::Rendering::Vertex> &vertices, 
				const std::vector<int> &indices);
		};
	}
}

#endif