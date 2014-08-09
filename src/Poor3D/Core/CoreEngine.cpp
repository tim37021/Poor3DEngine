#include <GLFW/glfw3.h>
#include <Poor3D/Core/CoreEngine.h>
#include <Poor3D/Core/Time.h>

using namespace Poor3D::Core;
using namespace Poor3D::Window;

CoreEngine::CoreEngine(Game *_g, double frameRate)
	:frameTime(1.0/frameRate), 
	window(nullptr), 
	mouse(new P3DMouse()), 
	keybd(new P3DKeyboard),
	game(_g), 
	isRunning(false)
{
	game->setEngine(this);
	glfwInit();
}

CoreEngine::~CoreEngine()
{
	delete window;
	delete mouse;
	delete keybd;
	glfwTerminate();
}

void CoreEngine::createWindow(int width, int height,
	const char *title)
{
	window = new P3DWindow(width, height, title);
	mouse->setWindow(window);
	keybd->setWindow(window);
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
	while(isRunning && !window->isCloseRequested())
	{
		while(getTime() - lastRenderTime <= frameTime)
		{
			//Update game
			mouse->update();
			keybd->update();
			game->update();
		}
		lastRenderTime = getTime();

		game->render();
		window->update();
	}
}