uniform mat4 model;
uniform float angle;

void main(void){
	//gl_Position=vec4(cos(angle)*gl_Vertex.x+gl_Vertex.y*-sin(angle), sin(angle)*gl_Vertex.x+cos(angle)*gl_Vertex.y, 0.0, 1.0);
  gl_Position=model*gl_Vertex;
}
