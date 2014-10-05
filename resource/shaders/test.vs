#version 120

attribute vec3 pos;
attribute vec3 normal;

uniform mat4 modelview;
uniform mat4 proj;
uniform mat4 rotate;

varying vec4 vNormal;
varying vec4 vPos;

void main(void){	
	vNormal=rotate*vec4(normal, 1.0);
	vPos=modelview*vec4(pos, 1.0);
	gl_Position=proj*modelview*vec4(pos, 1.0);
}
