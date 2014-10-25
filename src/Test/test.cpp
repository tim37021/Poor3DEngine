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
	Math::Mat4 proj;
	Scene::WalkerCamera cam;
	Scene::SceneNode *obj;
	double lasttime, lastUpdate;

	myGame()
		: sc(new Scene::Scene()), 
			cam(Math::Vec3f(), Math::Vec3f(0, 0, 10.0f), Math::Vec3f(0, 1, 0)),
			lasttime(0.0f), lastUpdate(0.0f)
	{
		angle=0.0f;
		proj = Math::PerspectiveProjMatrix(toRadian(30.0f), 800.0f/600.0f, 0.1f, 200.0f);

	}

	virtual void buildScene()
	{
		Rendering::Mesh *monkey = Utils::loadObjMesh("resource/models/monkey_high.obj");
		sc->attach(new Scene::SceneNode(monkey, new Rendering::Material()));
		
		Rendering::Mesh *circle = Utils::loadObjMesh("resource/models/untitled.obj");
		obj=sc->objects[0]->attach(new Scene::SceneNode(circle, new Rendering::Material()));

		renderEngine = new Rendering::RenderEngine();
	}

	virtual void update()
	{
		angle=3.1415926f*Core::getTime();
		sc->objects[0]->getTransform()->setRotation(0.0f, 0.0f, angle);
		obj->getTransform()->setTranslate(0.0, 1.0f, 10);
		obj->getTransform()->setRotation(0.0f, 0.0f, angle);
		//ESC
		if(engine->getKeyboard()->keyUp(256)){
			engine->stop();
		}

		float deltaT=Core::getTime()-lastUpdate;

		if(engine->getKeyboard()->getKeyState(265)){
			cam.moveForward(deltaT*10.0f);
			//fprintf(stderr, "SHIT");
		}
		if(engine->getKeyboard()->getKeyState(264))
			cam.moveForward(-deltaT*10.0f);
		if(engine->getKeyboard()->getKeyState(263))
			cam.turn(deltaT*3.1415926f);
		if(engine->getKeyboard()->getKeyState(262))
			cam.turn(-deltaT*3.1415926f);
		lastUpdate=Core::getTime();
	}
	virtual void render()
	{
		if(Core::getTime()-lasttime>=1.0){
			char buf[30];
			sprintf(buf, "Default - %d fps", engine->getWindow()->getFPS());
			engine->getWindow()->setTitle(buf);
			lasttime=Core::getTime();
		}

		renderEngine->render(proj, cam, sc);
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
	Core::CoreEngine engine(g, 9999);

	engine.createWindow(800, 600, "Default");
	engine.start();

	return 0;
}
