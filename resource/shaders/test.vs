uniform mat4 model;

void main(void){
	gl_Position=model*gl_Vertex;
}
