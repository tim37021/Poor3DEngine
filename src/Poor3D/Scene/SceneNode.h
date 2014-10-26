#ifndef SCENE_SCENENODE_H_
#define SCENE_SCENENODE_H_

#include <Poor3D/Math/TransMat4.h>
#include <Poor3D/Rendering/Mesh.h>
#include <Poor3D/Rendering/Material.h>
#include <Poor3D/Scene/Scene_def.h>
#include <vector>

namespace Poor3D
{
	namespace Scene
	{
		class Scene;
		class SceneNode
		{
		public:
			SceneNode(Poor3D::Rendering::Mesh *mesh, Poor3D::Rendering::Material *material);
			~SceneNode();
			Poor3D::Math::TransMat4 *getTransform()
				{return &m_trans;}
			SceneNode *attach(SceneNode *);
			void render(Scene *sc);
			void render(Scene *sc, 
				const Poor3D::Math::Mat4 &parentModel, 
				const Poor3D::Math::Mat4 &parentRotation);

		private:
			Poor3D::Rendering::Mesh *m_mesh;
			Poor3D::Rendering::Material *m_material;
			Poor3D::Math::TransMat4 m_trans;
			std::vector<SceneNode *> m_children;
		};
	}
}


#endif