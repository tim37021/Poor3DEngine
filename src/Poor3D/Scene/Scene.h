#ifndef SCENE_SCENE_H_
#define SCENE_SCENE_H_

#include <Poor3D/Poor3D.h>
#include <vector>
#include <Poor3D/Scene/Camera.h>
#include <Poor3D/Scene/WalkerCamera.h>
#include <Poor3D/Scene/SceneNode.h>

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
			Poor3D::Scene::SceneNode *attach(Poor3D::Scene::SceneNode *obj)
			{
				objects.push_back(obj);
				return obj;
			}
			std::vector<Poor3D::Scene::SceneNode *> objects;
		};
	}
}

#endif
