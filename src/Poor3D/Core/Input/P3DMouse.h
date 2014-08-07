#ifndef CORE_INPUT_P3DMOUSE_H_
#define CORE_INPUT_P3DMOUSE_H_

#include <Poor3D/Core/Rendering/P3DWindow.h>
#include <vector>

namespace Poor3D
{
	namespace Core
	{
		namespace Input
		{
			class P3DMouse
			{
			public:
				//some static constant
				static const int MOUSE_BUTTON_1 = 0;
				static const int MOUSE_BUTTON_2 = 1;
				static const int MOUSE_BUTTON_3 = 2;
				static const int MOUSE_BUTTON_4 = 3;
				static const int MOUSE_BUTTON_5 = 4;
				static const int MOUSE_BUTTON_6 = 5;
				static const int MOUSE_BUTTON_7 = 6;
				static const int MOUSE_BUTTON_8 = 7;

				static const int MOUSE_BUTTON_LAST = MOUSE_BUTTON_8;
				static const int MOUSE_BUTTON_LEFT = MOUSE_BUTTON_1;
				static const int MOUSE_BUTTON_RIGHT = MOUSE_BUTTON_2;
				static const int MOUSE_BUTTON_MIDDLE = MOUSE_BUTTON_3;
				
				P3DMouse()=default;
				P3DMouse(Poor3D::Core::Rendering::P3DWindow *window);
				void update();
				void setWindow(Poor3D::Core::Rendering::P3DWindow *_w)
				{ window = _w; }

				void getPosition(double *x, double *y) const;
				//check mouse state in this update
				bool mouseDown(int button) const
					{ return down[button]; }
				bool mouseUp(int button) const
					{ return up[button]; }

				bool getButtonState(int button) const;			private:
				//Current pressed button
				bool current[8];
				bool down[8];
				bool up[8];

				Poor3D::Core::Rendering::P3DWindow *window;
			};
		}
	}
}

#endif