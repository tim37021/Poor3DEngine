#version 330

#define MAX_LIGHTS 8

in vec4 vNormal;
in vec4 vPos;
in vec2 vTexCoord;
uniform vec3 Eye;

uniform sampler2D textureSampler;
uniform vec3 diffuse;
uniform float specular;
uniform float shininess;

struct PointLight
{
	vec3 pos;
	vec3 color;
};

struct SpotLight
{
	vec3 pos;
	vec3 color;
	vec3 dir;
	float inner_angle;
	float outer_angle;
};

uniform int pointlightCount;
uniform PointLight plights[MAX_LIGHTS];

uniform int spotlightCount;
uniform SpotLight slights[MAX_LIGHTS];

//Point light shader
vec3 pLight(int index)
{
	vec3 lDir=plights[index].pos-vPos.xyz;
	float dist=length(lDir);
	lDir=normalize(lDir);

	float cosin_dir=dot(lDir, vNormal.xyz);

	vec3 m_diffuse;
	if(diffuse.x>0)
		m_diffuse=diffuse;
	else
		m_diffuse=texture2D(textureSampler, vTexCoord).rgb;

	if(cosin_dir>0.0)
	{
		float cosin_reflect=max(dot(reflect(-lDir, vNormal.xyz), normalize(Eye-vPos.xyz)), 0.0);
		cosin_reflect=pow(cosin_reflect, shininess);
		return (cosin_dir*plights[index].color*m_diffuse + specular*cosin_reflect*plights[index].color)/(0.1+0.05*dist+0.05*dist*dist);
	}
	return vec3(0.0, 0.0, 0.0);
}

//Spot light shader with falloff
vec3 sLight(int index)
{
	vec3 lDir=slights[index].pos-vPos.xyz;
	float dist=length(lDir);
	lDir=normalize(lDir);

	float cosin=dot(normalize(-slights[index].dir), lDir);
	float cos_inner_cone_angle=cos(slights[index].inner_angle);
	float cos_outer_cone_angle=cos(slights[index].outer_angle);;
	float cos_inner_minus_outer_angle=cos_inner_cone_angle-cos_outer_cone_angle;

	//use clamp to prevent dynamic branching
	float fallout=clamp((cosin-cos_outer_cone_angle)/cos_inner_minus_outer_angle, 0.0, 1.0);

	float cosin_dir=dot(lDir, vNormal.xyz);

	vec3 m_diffuse;
	if(diffuse.x>0)
		m_diffuse=diffuse;
	else
		m_diffuse=texture2D(textureSampler, vTexCoord).rgb;
	if(cosin_dir>0.0)
	{
		float cosin_reflect=max(dot(reflect(-lDir, vNormal.xyz), normalize(Eye-vPos.xyz)), 0.0);
		cosin_reflect=pow(cosin_reflect, shininess);
		return fallout*(cosin_dir*slights[index].color*m_diffuse + specular*cosin_reflect*slights[index].color)/(0.1+0.1*dist+0.1*dist*dist);
	}
	return vec3(0.0, 0.0, 0.0);
}

void main(void){
	vec3 result=vec3(0.0, 0.0, 0.0);
	int i;
	for(i=0; i<pointlightCount; i++){
		result+=pLight(i);
	}

	for(i=0; i<spotlightCount; i++){
		result+=sLight(i);
	}

	gl_FragColor=vec4(result, 1.0);
}
