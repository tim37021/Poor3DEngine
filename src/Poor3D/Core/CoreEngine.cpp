#include <Poor3D/Poor3D.h>
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
	window = new P3DWindow(width, height, title, 2, 1);
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

	glewExperimental = GL_TRUE;
	GLenum err=glewInit();
	if (err != GLEW_OK)
		throw std::runtime_error("GLEW FAILED");

	if (!glewIsSupported("GL_VERSION_2_1"))
		throw std::runtime_error("This application need OpenGL 2.1");

	game->buildScene();

	double lastRenderTime = getTime();
	while(isRunning && !window->isCloseRequested())
	{
		bool hasUpdate = false;
		while(getTime() - lastRenderTime <= frameTime)
		{
			//Update game
			mouse->update();
			keybd->update();
			game->update();
			hasUpdate=true;
		}

		if(!hasUpdate){
			//Update game if the while loop didn't run
			mouse->update();
			keybd->update();
			game->update();
		}
		game->render();
		window->update();

		lastRenderTime = getTime();
	}
}
