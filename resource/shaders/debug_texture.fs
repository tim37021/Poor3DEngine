#version 330

in vec2 vTexCoord;

uniform sampler2D textureSampler;

void main()
{
	gl_FragColor = texture(textureSampler, vTexCoord);
}