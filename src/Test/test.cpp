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
	float angle;
	Scene::WalkerCamera cam;
	Scene::SceneNode *obj;
	double lasttime, lastUpdate;
	Rendering::Light *light;
	

	myGame()
		:	cam(Math::Vec3f(0, 1, 0), Math::Vec3f(5, 1, 0), Math::Vec3f(0, 1, 0)),
			lasttime(0.0f), lastUpdate(0.0f)
	{
		sc = new Scene::Scene(&cam);
		cam.setPerspective(toRadian(30.0f), 800.0f/600.0f, 0.1f, 200.0f);
		angle=0.0f;
	}

	virtual void buildScene()
	{
		
		//Load textures
		Utils::BITMAP_FILEHEADER *header;
		Utils::BITMAP_INFOHEADER *info;
		unsigned char *bmp=Utils::loadBMP("resource/texture/blade.bmp", &header, &info);
		Rendering::Texture *text = new Rendering::ImageTexture(info->width, info->height, Utils::getBMPRaw(bmp, header));
		delete [] bmp;

		//Create Material
		Rendering::PhongMaterial *m, *m2;
		m=new Rendering::PhongMaterial(text);
		m2=new Rendering::PhongMaterial(Math::Vec3f(0.4, 0.4, 0.4));
		
		Rendering::Mesh *dragon = Utils::loadObjMesh("resource/models/dragon.obj");
		obj=sc->attach(new Scene::SceneNode(dragon, m2));
		Rendering::Mesh *monkey = Utils::loadObjMesh("resource/models/blade.obj");
		sc->attach(new Scene::SceneNode(monkey, m));
		sc->attach(new Scene::SceneNode(Utils::loadObjMesh("resource/models/plane.obj"), m2));

		//Add lights
		light=sc->attach(new Rendering::SpotLight(Math::Vec3f(10, 5, 0),
			Math::Vec3f(20.0f, 16.0f, 16.0f), Math::Vec3f()-Math::Vec3f(10, 5, 0),  toRadian(30.0f), toRadian(60.0f)));
		sc->attach(new Rendering::Light(Math::Vec3f(-10, 5, 7), Math::Vec3f(16.0f, 16.0f, 16.0f)));

		//Bind the lights array to the materials
		m->bindLights(sc->getLights());
		m2->bindLights(sc->getLights());

		renderEngine = new Rendering::RenderEngine();
	}

	virtual void update()
	{
		angle=3.1415926f*Core::getTime();

		obj->getTransform()->setTranslate(0.0, sinf(angle), 0.0);

		//ESC
		if(engine->getKeyboard()->keyUp(256))
			engine->stop();
		
		float deltaT=Core::getTime()-lastUpdate;

		if(engine->getKeyboard()->getKeyState(265))
			cam.moveForward(deltaT*10.0f);
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

		renderEngine->updateShadowMap(sc);
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
	Core::CoreEngine engine(g, 9999);

	engine.createWindow(800, 600, "Default");
	engine.start();

	return 0;
}
