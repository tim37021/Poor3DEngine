#ifndef SCENE_SCENE_H_
#define SCENE_SCENE_H_

#include <Poor3D/Poor3D.h>
#include <vector>

namespace Poor3D
{
	namespace Scene
	{
		class Scene
		{
		public:
			~Scene()
			{
				for(int i=0; i<objects.size(); i++)
					delete objects[i];
			}
			std::vector<Poor3D::Rendering::Mesh *> objects;
		};
	}
}

#endif