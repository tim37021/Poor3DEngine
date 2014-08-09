#include "P3DWindow.h"
#include <Poor3D/Core/Time.h>
#include <stdexcept>

using namespace Poor3D::Window;
using namespace Poor3D::Core;

P3DWindow::P3DWindow(int _w, int _h, const char *_t, int major, int minor)
	: frames(0), width(_w), height(_h), title(_t)
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor);
	window = glfwCreateWindow(width, height, _t, NULL, NULL);
	if(!window)
		throw std::runtime_error("Cannot create window!");

	lastFPSUpdate = getTime();
}

P3DWindow::~P3DWindow()
{
	glfwDestroyWindow(window);
}

void P3DWindow::update()
{
	frames++;

	if(getTime() - lastFPSUpdate >= 1.0)
	{
		FPS = frames;
		frames = 0;
		lastFPSUpdate = getTime();
	}

	glfwSwapBuffers(window);
	glfwPollEvents();
}

bool P3DWindow::isCloseRequested() const
{
	return glfwWindowShouldClose(window);
}

void P3DWindow::setTitle(const char *_t)
{
	glfwSetWindowTitle(window, _t);
	title = _t;
}

void P3DWindow::setSize(int _w, int _h)
{
	width = _w;
	height = _h;
	glfwSetWindowSize(window, width, height);
}

void P3DWindow::makeCurrent() const
{
	glfwMakeContextCurrent(window);
}

#ifdef DEBUG

//draw a sweet triangle
int main(int argc, char *argv[])
{
	glfwInit();

	P3DWindow *myWindow = new P3DWindow(800, 600, "Hello world");

	myWindow->makeCurrent();

	while(!myWindow->shouldClose())
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glBegin(GL_TRIANGLES);
		glVertex2d(0.0, 1.0);
		glVertex2d(-1.0, -1.0);
		glVertex2d(1.0, -1.0);
		glEnd();
		myWindow->update();
	}

	glfwTerminate();
	return 0;
}

#endif