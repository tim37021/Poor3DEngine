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

uniform PointLight plights[MAX_LIGHTS];
uniform int lightCount;


vec3 pLight(int index)
{
	vec3 lDir=normalize(plights[index].pos-vPos.xyz);
	float cosin_dir=max(dot(lDir, vNormal.xyz), 0.0);
	float cosin_reflect=max(dot(reflect(-lDir, vNormal.xyz), normalize(Eye-vPos.xyz)), 0.0);
	cosin_reflect=pow(cosin_reflect, shininess);
	return cosin_dir*plights[index].color*diffuse + specular*cosin_reflect*plights[index].color;
}

void main(void){
	vec3 result=vec3(0.0, 0.0, 0.0);
	int i;
	for(i=0; i<lightCount; i++){
		result+=pLight(i);
	}

	gl_FragColor=vec4(result, 1.0);
}
