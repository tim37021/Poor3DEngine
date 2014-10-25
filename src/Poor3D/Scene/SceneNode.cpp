#include <Poor3D/Scene/SceneNode.h>

using namespace Poor3D::Math;
using namespace Poor3D::Rendering;
using namespace Poor3D::Scene;

SceneNode::SceneNode(Mesh *mesh, Material *material)
	: m_mesh(mesh), m_material(material)
{

}

SceneNode::~SceneNode()
{
	delete m_mesh;

	for(auto child: m_children)
		delete child;
}

SceneNode *SceneNode::attach(SceneNode *child)
{
	m_children.push_back(child);
	return child;
}

void SceneNode::render(const Mat4 &proj, Camera &cam)
{
	Mat4 identity; identity.setIdentity();
	m_material->bind(proj, cam, identity, identity, m_trans);
	m_mesh->render();

	for(auto child: m_children)
		child->render(proj, cam, m_trans.getMatrix(), m_trans.getRotationMatrix());
}

void SceneNode::render(const Mat4 &proj, 
	Camera &cam, 
	const Mat4 &parentModel, 
	const Mat4 &parentRotation)
{
	m_material->bind(proj, cam, parentModel, parentRotation, m_trans);
	m_mesh->render();

	for(auto child: m_children)
		child->render(proj, cam, parentModel*m_trans.getMatrix(), parentRotation*m_trans.getRotationMatrix());
}