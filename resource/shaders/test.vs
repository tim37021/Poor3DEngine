#version 330

layout(location=0) in vec3 pos;
layout(location=1) in vec3 normal;

uniform mat4 mvp;
uniform mat4 rotate;
uniform mat4 model;

varying vec4 vNormal;
varying vec4 vPos;

void main(void){	
	vNormal=rotate*vec4(normal, 1.0);
	vPos=model*vec4(pos, 1.0);
	gl_Position=mvp*vec4(pos, 1.0);
}
