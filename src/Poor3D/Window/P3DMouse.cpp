#include <Poor3D/Window/P3DMouse.h>
#include <GLFW/glfw3.h>

using namespace Poor3D::Window;

P3DMouse::P3DMouse(P3DWindow *_w)
	:window(_w)
{

}

void P3DMouse::update()
{
	for(int i=0; i<8; i++)
	{
		bool state=getButtonState(i);

		down[i] = false;
		up[i] = false;
		//if last state is not equal to current state
		if(current[i] ^ state)
		{
			if(state)
				down[i] = true;
			else
				up[i] = true;
		}

		current[i] = state;
	}
}

void P3DMouse::getPosition(double *x, double *y) const 
{
	glfwGetCursorPos(window->getHandler(), x, y);
}

bool P3DMouse::getButtonState(int button) const
{
	return (glfwGetMouseButton(window->getHandler(), button)==GLFW_PRESS);
}