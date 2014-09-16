#include <Poor3D/Poor3D.h>

#include <iostream>
#include <vector>

using namespace Poor3D;
using namespace std;

class myGame: public Core::Game
{
public:
	Rendering::RenderEngine *renderEngine;
	Scene::Scene *sc;
	Shader::Shader *shader;
	float angle;
	Math::TransMat4 t;
	
	myGame()
		: sc(new Scene::Scene())
	{
		angle=0.0f;
	}

	virtual void buildScene()
	{
		vector<Math::Vec3f> vec = {{0.0, 1.0, 0.0}, {-1.0, -1.0, 0.0}, {1.0, -1.0, 0.0}};
		vector<int> ind = {0, 1, 2};
		Rendering::Mesh *triangle = new Rendering::Mesh(vec, ind);
		sc->objects.push_back(triangle);
	
		shader = new Shader::Shader("./resource/shaders/test.vs", "./resource/shaders/test.fs");
		renderEngine = new Rendering::RenderEngine();
	}

	virtual void update()
	{
		angle+=0.0001f;
		//t.setScale(sin(angle), 1.0f, 1.0f);
		t.setRotation(angle, Math::Vec3f(0.0f, 0.0f, 1.0f));
		//ESC
		if(engine->getKeyboard()->keyUp(256)){
			engine->stop();
		}
	}
	virtual void render()
	{
		shader->bind();
		GLuint ref=glGetUniformLocation(shader->getID(), "model");	
		glUniformMatrix4fv(ref, 1, 0, &t.getMatrix().data[0][0]);
		renderEngine->render(sc);
	}
};

int main(int argc, char *argv[])
{

	myGame *g = new myGame();
	Core::CoreEngine engine(g);

	engine.createWindow(800, 600, "Default");
	engine.start();
	
	return 0;
}
