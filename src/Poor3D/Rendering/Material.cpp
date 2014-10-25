#include <Poor3D/Rendering/Material.h>

using namespace Poor3D::Rendering;
using namespace Poor3D::Scene;
using namespace Poor3D::Math;

Material::Material()
	: m_shader("./resource/shaders/test.vs", "./resource/shaders/test.fs")
{

}

void Material::bind(const Mat4 &proj, 
	Camera &cam, 
	const Mat4 &parentModel,
	const Mat4 &parentRotation,
	TransMat4 &t) const
{
	//rotate, model, eye is used for calculating 

	m_shader.bind();
	const Mat4 tmpMatrix=parentModel*t.getMatrix();
	m_shader.setUniform("model", tmpMatrix);
	m_shader.setUniform("mvp", proj*cam.getMatrix()*tmpMatrix);
	m_shader.setUniform("rotate", parentRotation*t.getRotationMatrix());
	m_shader.setUniform("Eye", cam.getPosition());
}