#ifndef SCENE_SCENE_DEF_H_
#define SCENE_SCENE_DEF_H_

#include <Poor3D/Rendering/Light.h>
#include <Poor3D/Scene/Camera.h>
#include <Poor3D/Scene/SceneNode.h>
#include <vector>


namespace Poor3D
{
	namespace Scene
	{
		class SceneNode;
		class Scene
		{
		public:
			Scene(Camera *cam);
			~Scene();

			SceneNode *attach(Poor3D::Scene::SceneNode *obj);

			Poor3D::Rendering::Light *attach(Poor3D::Rendering::Light *light);

			Camera *getCamera()
				{ return m_camera; } 

			const std::vector<Poor3D::Scene::SceneNode *> *getRootNodeList() const
				{ return &m_objects; }
			const std::vector<Poor3D::Rendering::Light *> *getLights() const
				{ return &m_lights; }
		private:
			Camera *m_camera;
			std::vector<Poor3D::Scene::SceneNode *> m_objects;
			std::vector<Poor3D::Rendering::Light *> m_lights;

		};
	}
}

#endif