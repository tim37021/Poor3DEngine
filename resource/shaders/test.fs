#version 120

varying vec4 vNormal;
varying vec4 vPos;
vec3 lDir=vec3(-0.1, -0.1, -0.1);
vec3 lColor=vec3(0.8, 0.8, 0.0);
vec3 objColor=vec3(0.3, 0.3, 0.3);
vec3 E=vec3(0.0, 0.0, 0.0);

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
	float specular=max(dot(reflect(-lDir, vNormal.xyz), normalize(E-vPos.xyz)), 0.0);
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

/*float diffuse=max(dot(vec4(normalize(lDir), 0.0), vNormal), 0.0);
  float specular=max(dot(reflect(normalize(-lDir), vNormal.xyz), normalize(E-vPos.xyz)), 0.0);
	specular = pow(specular, 10.0);
	gl_FragColor = vec4(diffuse*lColor*objColor+specular*vec3(1.0, 1.0, 1.0), 1.0);*/
}
