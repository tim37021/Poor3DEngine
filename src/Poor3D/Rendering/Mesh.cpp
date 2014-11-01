#include <Poor3D/Poor3D.h>

using namespace Poor3D::Rendering;
using namespace Poor3D::Math;

Mesh::Mesh(std::vector<Vertex> &vertices, 
	const std::vector<int> &indices)
{
	addVertices(vertices, indices);
}

Mesh::~Mesh()
{
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &ibo);
	glDeleteVertexArrays(1, &vao);
}

void Mesh::render() const
{
	glBindVertexArray(vao);
	glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, nullptr);
}

void Mesh::addVertices(std::vector<Vertex> &vertices, 
	const std::vector<int> &indices)
{
	indicesCount = indices.size();
	calcNormals(vertices, indices);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);

	//generate vertex buffer
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*vertices.size(), vertices.data(), GL_STATIC_DRAW);
	//pos
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
	//texCoord
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)sizeof(Vec3f));
	//normal
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)(sizeof(Vec3f)+sizeof(Vec2f)));

	//generate index buffer
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*indices.size(), indices.data(), GL_STATIC_DRAW);

	//default state
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

#include <cstdio>

void Mesh::calcNormals(std::vector<Vertex> &vertices, 
	const std::vector<int> &indices) const
{
	for(unsigned int i=0; i<indices.size(); i+=3)
	{
		const Vec3f &o=vertices[indices[i]].pos;
		const Vec3f &a=vertices[indices[i+1]].pos;
		const Vec3f &b=vertices[indices[i+2]].pos;

		Vec3f normal=(a-o).cross(b-o);
		normal.normalize();

		//We use +=, taking adventage of Vec3f default init(to zero).
		vertices[indices[i]].normal+=normal;
		vertices[indices[i+1]].normal+=normal;
		vertices[indices[i+2]].normal+=normal;
	}

	//normalize all the vertex normals to achieve smooth shading
	for(unsigned int i=0; i<vertices.size(); i++)
		vertices[i].normal.normalize();
}
