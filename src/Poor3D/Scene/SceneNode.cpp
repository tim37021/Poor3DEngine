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

void SceneNode::render(Poor3D::Scene::Scene *sc, const Material *material)
{
	Mat4 identity; identity.setIdentity();

	//Use explicit assigned material or not?
	material = material? material: m_material;

	material->bind(sc->getCamera()->getProjectionMatrix(), sc->getCamera(), identity, identity, m_trans);
	m_mesh->render();
	material->unbind();

	for(auto child: m_children)
		child->render(sc, m_trans.getMatrix(), m_trans.getRotationMatrix());
}

void SceneNode::render(Poor3D::Scene::Scene *sc,
	const Mat4 &parentModel, 
	const Mat4 &parentRotation,
	const Material *material)
{
	//Use explicit assigned material or not?
	material = material? material: m_material;

	material->bind(sc->getCamera()->getProjectionMatrix(), sc->getCamera(), parentModel, parentRotation, m_trans);
	m_mesh->render();
	material->unbind();

	for(auto child: m_children)
		child->render(sc, parentModel*m_trans.getMatrix(), parentRotation*m_trans.getRotationMatrix());
}