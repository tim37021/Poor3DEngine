#version 330

layout(location=0) in vec3 pos;
layout(location=1) in vec2 texCoord;
layout(location=2) in vec3 normal;

uniform mat4 mvp;
uniform mat4 rotate;
uniform mat4 model;

out vec4 vNormal;
out vec4 vPos;
out vec2 vTexCoord;

void main(void){	
	vNormal=rotate*vec4(normal, 1.0);
	vPos=model*vec4(pos, 1.0);
	vTexCoord=texCoord;
	gl_Position=mvp*vec4(pos, 1.0);
}
