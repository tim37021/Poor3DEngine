#include <Poor3D/Utils/Utils.h>
#include <Poor3D/Rendering/Mesh.h>
#include <Poor3D/Math/Vec3f.h>
#include <cstdio>
#include <vector>
#include <stdexcept>

using namespace std;
using namespace Poor3D;

Rendering::Mesh Utils::loadObjMesh(const char *filename)
{
	char linebuf[256];
	vector<Math::Vec3f> vertices;
	vector<int> indices;
	int i;
	float v[3];
	//indice
	int ind[3];

	FILE *fp=fopen(filename, "r");
	
	if(!fp)
		throw runtime_error("Cannot open file.");

	while(!feof(fp))
	{
		fgets(linebuf, 128, fp);
		
		switch(linebuf[0])
		{
			case 'v':
				sscanf(linebuf, "v %f %f %f", &v[0], &v[1], &v[2]);
				vertices.push_back({v[0], v[1], v[2]});
				break;
			case 'f':
				sscanf(linebuf, "f %d//%*d %d//%*d %d//%*d", 
						&ind[0], &ind[1], &ind[2]);
				for(i=0; i<3; i++)
					indices.push_back(i);
				break;
			//comment
			case '#':
			default:;
		}
	}
	fclose(fp);

	return Rendering::Mesh(vertices, indices);
}
