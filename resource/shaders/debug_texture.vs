#version 330

layout(location=0) in vec3 pos;
layout(location=1) in vec2 texCoord;
layout(location=2) in vec3 normal;

out vec2 vTexCoord;

void main()
{
	vTexCoord=texCoord;
	gl_Position=vec4(pos, 1.0);
}