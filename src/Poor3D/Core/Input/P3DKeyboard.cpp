#include <Poor3D/Core/Input/P3DKeyboard.h>
#include <GLFW/glfw3.h>

using namespace Poor3D::Core::Input;
using namespace Poor3D::Core::Rendering;

P3DKeyboard::P3DKeyboard(P3DWindow *_w)
	: window(_w)
{

}

#include <cstdio>

void P3DKeyboard::update()
{
	down.clear();
	up.clear();
	tmpState.clear();

	for(int i=0; i<350; i++)
	{
		bool state=getKeyState(i);
		bool lastState=(std::find(current.cbegin(), current.cend(), i)!=current.cend());
		if(lastState^state)
		{
			if(state)
				down.push_back(i);
			else
				up.push_back(i);
		}

		if(state)
			tmpState.push_back(i);
	}
	current = tmpState;
}

bool P3DKeyboard::getKeyState(int key) const
{
	return (glfwGetKey(window->getHandler(), key) == GLFW_PRESS);
}