#include <Poor3D/Core/CoreEngine.h>
#include <Poor3D/Core/Game.h>
#include <iostream>

using namespace Poor3D::Core;

class myGame: public Game
{
	virtual void update()
	{
		if(engine->getMouse()->mouseDown(0)){

			std::cout<<"Mouse Down"<<std::endl;
		}

		if(engine->getMouse()->mouseUp(0)){

			std::cout<<"Mouse Up"<<std::endl;
		}
	}
	virtual void render(){}
};

int main(int argc, char *argv[])
{
	myGame *g = new myGame();
	CoreEngine engine(g);

	engine.createWindow(800, 600, "Default");

	engine.start();
	return 0;
}