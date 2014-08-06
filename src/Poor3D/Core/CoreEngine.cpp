#include <GLFW/glfw3.h>
#include <Poor3D/Core/CoreEngine.h>
#include <Poor3D/Core/Time.h>
#include <iostream>

using namespace Poor3D::Core;

CoreEngine::CoreEngine(double frameRate)
	:frameTime(1.0/frameRate), window(nullptr), isRunning(false)
{
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
		}
		lastRenderTime = getTime();
		if(getTime() - lastDisplayFPS >= 1.0)
		{
			std::cout<<window->getFPS()<<std::endl;
			lastDisplayFPS = getTime();
		}

		window->update();
	}
}

#ifdef DEBUG
int main(int argc, char *argv[])
{
	CoreEngine engine(60.0);

	engine.createWindow(800, 600, "Default");

	engine.start();
	return 0;
}
#endif