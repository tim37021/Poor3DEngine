#ifndef UTILS_H_
#define UTILS_H_

#include <Poor3D/Poor3D.h>

namespace Poor3D
{
	namespace Utils
	{
		void createSphere(std::vector<Poor3D::Math::Vec3f> &outVertices, 
			std::vector<int> &outIndices, 
			int seg, int ring);
	}
}

#endif