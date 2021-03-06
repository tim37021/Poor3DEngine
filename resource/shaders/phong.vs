#version 400
#pragma optionNV(unroll all)

#define MAX_LIGHTS 8

layout(location=0) in vec3 pos;
layout(location=1) in vec2 texCoord;
layout(location=2) in vec3 normal;

uniform mat4 mvp;
uniform mat4 rotate;
uniform mat4 model;
uniform mat4 depthVP[MAX_LIGHTS];
uniform int spotlightCount;

out vec4 vNormal;
out vec4 vPos;
out vec2 vTexCoord;
out vec4 vSpotLightShadowCoord[MAX_LIGHTS];

void main(void){	
	vNormal=rotate*vec4(normal, 1.0);
	vPos=model*vec4(pos, 1.0);
	vTexCoord=texCoord;

	int i=0;

	vSpotLightShadowCoord[0]=depthVP[0]*vPos;
	//vSpotLightShadowCoord[0]=biasMatrix*vSpotLightShadowCoord[0];

	gl_Position=mvp*vec4(pos, 1.0);
}
