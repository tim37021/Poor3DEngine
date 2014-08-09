#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Poor3D/Core/CoreEngine.h>
#include <Poor3D/Core/Time.h>
#include <stdexcept>

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
	//Create OpenGL 3.3 context window
	window = new P3DWindow(width, height, title, 3, 3);
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

	GLenum err=glewInit();
	if (err != GLEW_OK)
		throw std::runtime_error("GLEW FAILED");

	if (!glewIsSupported("GL_VERSION_3_3"))
		throw std::runtime_error("This application need OpenGL 3.3");

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