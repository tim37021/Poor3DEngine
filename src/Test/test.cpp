#include <Poor3D/Poor3D.h>

#include <iostream>
#include <vector>

using namespace Poor3D;
using namespace std;


void print(const Math::Mat4 &m)
{
	for(int i=0; i<4; i++)
	{
		for(int j=0; j<4; j++)
		{
			cout<<m.data[i][j]<<" ";	
		}
		cout<<endl;
	}
}

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
		Rendering::Mesh *triangle = Utils::loadObjMesh("resource/models/monkey.obj");
		sc->objects.push_back(triangle);
	
		shader = new Shader::Shader("./resource/shaders/test.vs", "./resource/shaders/test.fs");
		renderEngine = new Rendering::RenderEngine();
	}

	virtual void update()
	{
		angle+=0.0001f;
		//t.setScale(sin(angle), 1.0f, 1.0f);
		t.setRotation(0.0f, 0.0f, angle);
		//ESC
		if(engine->getKeyboard()->keyUp(256)){
			engine->stop();
		}
	}
	virtual void render()
	{
		shader->bind();
		Math::Mat4 m;
		m.setIdentity();
		shader->setUniform("model", m);
		renderEngine->render(sc);
	}
};

void print(const Math::Mat3 &m)
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout<<m.data[i][j]<<" ";	
		}
		cout<<endl;
	}
}

int main(int argc, char *argv[])
{

	myGame *g = new myGame();
	Core::CoreEngine engine(g);

	engine.createWindow(800, 600, "Default");
	engine.start();

	return 0;
}
