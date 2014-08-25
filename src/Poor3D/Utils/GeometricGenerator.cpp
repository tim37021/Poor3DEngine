#include <Poor3D/Poor3D.h>
#include <cmath>

#define PI 3.1415926f

using namespace Poor3D;

void Utils::createSphere(std::vector<Math::Vec3f> &vertices, 
	std::vector<int> &indices, int segments, int rings)
{
	int seg;
	for(int i=0; i<ring; i++)
	{
		if(i==0||i==ring-1)
			seg=1;
		else
			seg=segments;

		for(int j=0; j<seg; j++)
		{
			float theta=(2.0f*PI/segments)*j;
			float phi=;
		}
	}
}