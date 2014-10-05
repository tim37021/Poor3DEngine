#include <Poor3D/Poor3D.h>

using namespace Poor3D::Rendering;
using namespace Poor3D::Math;

Mesh::Mesh(const std::vector<Vec3f> &vertices, 
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

void Mesh::addVertices(const std::vector<Vec3f> &vertices, 
	const std::vector<int> &indices)
{
	std::vector<Vertex> &data = *new std::vector<Vertex>();
	indicesCount = indices.size();
	calcNormals(data, vertices, indices);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	//generate vertex buffer
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*data.size(), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), nullptr);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)sizeof(Vec3f));

	//generate index buffer
	glGenBuffers(1, &ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int)*indices.size(), indices.data(), GL_STATIC_DRAW);

	//default state
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	delete &data;
}

#include <cstdio>

void Mesh::calcNormals(std::vector<Vertex> &out,
	const std::vector<Poor3D::Math::Vec3f> &vertices, 
	const std::vector<int> &indices) const
{
	out.clear();
	out.resize(vertices.size());
	for(int i=0; i<indices.size(); i+=3)
	{
		const Vec3f &o=vertices[indices[i]];
		const Vec3f &a=vertices[indices[i+1]];
		const Vec3f &b=vertices[indices[i+2]];

		Vec3f normal=(a-o).cross(b-o);
		normal.normalize();

		//We use +=, taking adventage of Vec3f default init(to zero).
		out[indices[i]].pos=o;
		out[indices[i]].normal+=normal;

		out[indices[i+1]].pos=a;
		out[indices[i+1]].normal+=normal;

		out[indices[i+2]].pos=b;
		out[indices[i+2]].normal+=normal;
	}

	//normalize all the vertex normals to achieve smooth shading
	for(int i=0; i<out.size(); i++)
		out[i].normal.normalize();
}
