#version 330

layout(location=0) in vec3 pos;
layout(location=1) in vec2 texCoord;
layout(location=2) in vec3 normal;


uniform mat4 model;
uniform mat4 mvp;

void main(void)
{	
	gl_Position=mvp*vec4(pos, 1.0);
}
