#version 330

varying vec4 vNormal;
varying vec4 vPos;
uniform vec3 Eye;
vec3 objColor=vec3(0.3, 0.3, 0.3);

struct PointLight
{
	vec3 pos;
	vec3 color;
};

PointLight plights[]=PointLight [](
	PointLight(vec3(10.0, 0.0, 7.0), vec3(1.0, 0.8, 0.0)),
	PointLight(vec3(-10.0, 0.0, 7.0), vec3(0.0, 0.8, 0.8))
);


vec3 pLight(int index)
{
	vec3 lDir=normalize(plights[index].pos-vPos.xyz);
	float diffuse=max(dot(lDir, vNormal.xyz), 0.0);
	float specular=max(dot(reflect(-lDir, vNormal.xyz), normalize(Eye-vPos.xyz)), 0.0);
	specular=pow(specular, 100.0);
	return diffuse*plights[index].color*objColor + specular*plights[index].color;
}

void main(void){
	vec3 result=vec3(0.0, 0.0, 0.0);
	int i;
	for(i=0; i<2; i++){
		result+=pLight(i);
	}

	gl_FragColor=vec4(result, 1.0);
}
