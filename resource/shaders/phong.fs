#version 330

#define MAX_LIGHTS 8

varying vec4 vNormal;
varying vec4 vPos;
uniform vec3 Eye;

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
	float angle;	
};

uniform int pointlightCount;
uniform PointLight plights[MAX_LIGHTS];

uniform int spotlightCount;
uniform SpotLight slights[MAX_LIGHTS];
float cos_outer_cone_angle=0.9659258262; //7 degree

//Point light shader
vec3 pLight(int index)
{
	vec3 lDir=plights[index].pos-vPos.xyz;
	float dist=length(lDir);
	lDir=normalize(lDir);

	float cosin_dir=dot(lDir, vNormal.xyz);
	if(cosin_dir>0.0)
	{
		float cosin_reflect=max(dot(reflect(-lDir, vNormal.xyz), normalize(Eye-vPos.xyz)), 0.0);
		cosin_reflect=pow(cosin_reflect, shininess);
		return (cosin_dir*plights[index].color*diffuse + specular*cosin_reflect*plights[index].color)/(0.1+0.05*dist+0.05*dist*dist);
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
	float cos_inner_cone_angle=cos(slights[index].angle);
	float cos_inner_minus_outer_angle=cos_inner_cone_angle-cos_outer_cone_angle;

	//use clamp to prevent dynamic branching
	float fallout=clamp((cosin-cos_outer_cone_angle)/cos_inner_minus_outer_angle, 0.0, 1.0);

	float cosin_dir=dot(lDir, vNormal.xyz);
	if(cosin_dir>0.0)
	{
		float cosin_reflect=max(dot(reflect(-lDir, vNormal.xyz), normalize(Eye-vPos.xyz)), 0.0);
		cosin_reflect=pow(cosin_reflect, shininess);
		return fallout*(cosin_dir*slights[index].color*diffuse + specular*cosin_reflect*slights[index].color)/(0.1+0.1*dist+0.1*dist*dist);
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
