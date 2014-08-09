#ifndef CORE_INPUT_P3DKEYBOARD_H_
#define CORE_INPUT_P3DKEYBOARD_H_

#include <vector>
#include <algorithm>
#include <Poor3D/Core/Rendering/P3DWindow.h>

namespace Poor3D
{
	namespace Core
	{
		namespace Input
		{
			class P3DKeyboard
			{
			public:
				P3DKeyboard();
				P3DKeyboard(Poor3D::Core::Rendering::P3DWindow *window);

				void update();
				void setWindow(Poor3D::Core::Rendering::P3DWindow *_w)
				{ window = _w; }

				bool keyDown(int key) const 
					{ return std::find(down.cbegin(), down.cend(), key)!=down.cend(); }
				bool keyUp(int key) const
					{ return std::find(up.cbegin(), up.cend(), key)!=up.cend(); }

				bool getKeyState(int key) const;
			private:
				Poor3D::Core::Rendering::P3DWindow *window;
			
				std::vector<int> *current;
				std::vector<int> *tmpState;
				std::vector<int> down;
				std::vector<int> up;
			};
		}
	}
}

#endif