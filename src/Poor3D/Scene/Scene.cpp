#include <Poor3D/Scene/Scene_def.h>
#include <Poor3D/Rendering/Light.h>

using namespace Poor3D::Scene;

Scene::Scene(Camera *cam): m_camera(cam){}

Scene::~Scene()
{
	for(unsigned int i=0; i<m_objects.size(); i++)
		delete m_objects[i];
	for(unsigned int i=0; i<m_lights.size(); i++)
		delete m_lights[i];
}


SceneNode *Scene::attach(Poor3D::Scene::SceneNode *obj)
{
	m_objects.push_back(obj);
	return obj;
}

Poor3D::Rendering::Light *Scene::attach(Poor3D::Rendering::Light *light)
{
	m_lights.push_back(light);
	return light;
}