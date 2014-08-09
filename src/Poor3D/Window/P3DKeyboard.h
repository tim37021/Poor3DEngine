#ifndef CORE_INPUT_P3DKEYBOARD_H_
#define CORE_INPUT_P3DKEYBOARD_H_

#include <vector>
#include <algorithm>
#include <Poor3D/Window/P3DWindow.h>

namespace Poor3D
{
	namespace Window
	{
		class P3DKeyboard
		{
		public:
			P3DKeyboard();
			P3DKeyboard(P3DWindow *window);
			~P3DKeyboard();

			void update();
			void setWindow(P3DWindow *_w)
			{ window = _w; }

			bool keyDown(int key) const 
				{ return std::find(down.cbegin(), down.cend(), key)!=down.cend(); }
			bool keyUp(int key) const
				{ return std::find(up.cbegin(), up.cend(), key)!=up.cend(); }

			bool getKeyState(int key) const;
		private:
			P3DWindow *window;
		
			std::vector<int> *current;
			std::vector<int> *tmpState;
			std::vector<int> down;
			std::vector<int> up;
		};
	}
}

#endif