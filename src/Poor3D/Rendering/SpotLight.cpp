#include <Poor3D/Poor3D.h>

using namespace Poor3D::Rendering;
using namespace Poor3D::Scene;
using namespace std;

SpotLight::SpotLight(const Poor3D::Math::Vec3f &p,
					const Poor3D::Math::Vec3f &c,
					const Poor3D::Math::Vec3f &dir,
					float inner, float outer)
	: Light(p, c), direction(dir), inner_angle(inner), outer_angle(outer)
{
	shadow_map.push_back(
		make_pair<Camera, DepthTexture *>(
			Camera(p, p+dir, Math::Vec3f(0, 1, 0)),
			new DepthTexture(1024, 1024))
	);

	shadow_map[0].first.setPerspective(outer_angle, 1.0f, 6.5f, 200.0f);
}

SpotLight::~SpotLight()
{

}

void SpotLight::setUniform(const Poor3D::Shader::Shader *shader, 
	int *pLightCount, int *sLightCount)
{
	std::string head="slights[";
	head+=std::to_string(*sLightCount)+"]";
	shader->setUniform((head+".pos").c_str(), position);
	shader->setUniform((head+".color").c_str(), color);
	shader->setUniform((head+".dir").c_str(), direction);
	shader->setUniform((head+".inner_angle").c_str(), inner_angle);
	shader->setUniform((head+".outer_angle").c_str(), outer_angle);

	//Bind shadow map
	shadow_map[0].second->bind(GL_TEXTURE1+*sLightCount);
	shader->setUniform("shadow_map[0]", *sLightCount+1);
	shader->setUniform("depthVP[0]", 
		shadow_map[0].first.getProjectionMatrix()*shadow_map[0].first.getMatrix());

	(*sLightCount)++;
}