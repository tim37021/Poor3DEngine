#include <GLFW/glfw3.h>
#include <Poor3D/Core/CoreEngine.h>
#include <Poor3D/Core/Time.h>
#include <iostream>

using namespace Poor3D::Core;

CoreEngine::CoreEngine(Game *_g, double frameRate)
	:frameTime(1.0/frameRate), 
	window(nullptr), 
	mouse(new Input::P3DMouse()), 
	game(_g), 
	isRunning(false)
{
	game->setEngine(this);
	glfwInit();
}

CoreEngine::~CoreEngine()
{
	glfwTerminate();
}

void CoreEngine::createWindow(int width, int height,
	const char *title)
{
	window = new Rendering::P3DWindow(width, height, title);
	mouse->setWindow(window);
}

void CoreEngine::start()
{
	//this make this calling won't go into infinite recursion
	//can also prevent starting game with no existing window
	if(isRunning||!window)
		return;
	run();
}

void CoreEngine::stop()
{
	isRunning = false;
}

void CoreEngine::run()
{
	isRunning = true;

	window->makeCurrent();

	double lastRenderTime = getTime();
	double lastDisplayFPS = getTime();
	while(isRunning && !window->isCloseRequested())
	{
		while(getTime() - lastRenderTime <= frameTime)
		{
			//Update game
			mouse->update();
			game->update();
		}
		lastRenderTime = getTime();
		if(getTime() - lastDisplayFPS >= 1.0)
		{
			std::cout<<window->getFPS()<<std::endl;
			lastDisplayFPS = getTime();
		}

		game->render();

		window->update();
	}
}