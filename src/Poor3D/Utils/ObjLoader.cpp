#include <Poor3D/Utils/Utils.h>
#include <Poor3D/Rendering/Mesh.h>
#include <Poor3D/Rendering/Vertex.h>
#include <Poor3D/Math/Vec3f.h>
#include <Poor3D/Math/Vec2f.h>
#include <cstdio>
#include <vector>
#include <stdexcept>

using namespace std;
using namespace Poor3D;

Rendering::Mesh *Utils::loadObjMesh(const char *filename)
{
	char linebuf[256];
	vector<Rendering::Vertex> vertices;
	vector<Math::Vec2f> texCoord;
	vector<int> indices;
	int i;
	float v[3];
	//indice
	int ind[3], in[3];

	FILE *fp=fopen(filename, "r");

	if(!fp)
		throw runtime_error("Cannot open file.");

	while(!feof(fp))
	{
		fgets(linebuf, 128, fp);

		switch(linebuf[0])
		{
			case 'v':
				if(linebuf[1]==' ')
				{
					sscanf(linebuf, "v %f %f %f", &v[0], &v[1], &v[2]);
					vertices.push_back({{v[0], v[1], v[2]}});
				}
				if(linebuf[1]=='t')
				{
					sscanf(linebuf, "vt %f %f", &v[0], &v[1]);
					texCoord.push_back({v[0], v[1]});
				}
				break;
			case 'f':
				sscanf(linebuf, "f %d/%d/%*d %d/%d/%*d %d/%d/%*d", 
						&ind[0], &in[0], &ind[1], &in[1], &ind[2], &in[2]);
				vertices[ind[0]-1].texCoord=texCoord[in[0]-1];
				vertices[ind[1]-1].texCoord=texCoord[in[1]-1];
				vertices[ind[2]-1].texCoord=texCoord[in[2]-1];
				for(i=0; i<3; i++)
					indices.push_back(ind[i]-1);
				break;
				//comment
			case '#':
			default:;
		}
		linebuf[0]='\0';
	}
	fclose(fp);

	return new Rendering::Mesh(vertices, indices);
}
