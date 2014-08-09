#ifndef CORE_COREENGINE_H_
#define CORE_COREENGINE_H_

#include <string>
#include <Poor3D/Window/P3DWindow.h>
#include <Poor3D/Core/Game.h>
#include <Poor3D/Window/P3DMouse.h>
#include <Poor3D/Window/P3DKeyboard.h>

namespace Poor3D{
	namespace Core
	{
		class Game;
		
		class CoreEngine
		{
		public:
			CoreEngine(Game *game, double frameRate=60.0);
			~CoreEngine();

			const Poor3D::Window::P3DMouse *getMouse() const
			{ return mouse; }
			const Poor3D::Window::P3DKeyboard *getKeyboard() const
			{ return keybd; }

			const Poor3D::Window::P3DWindow *getWindow() const 
			{ return window; }
			void createWindow(int width, int height,
				const char *title);

			void start();
			void stop();
		private:
			double frameTime;
			int width, height;

			Poor3D::Window::P3DWindow *window; 
			Poor3D::Window::P3DMouse *mouse;
			Poor3D::Window::P3DKeyboard *keybd;
			Game *game;
			bool isRunning;

			void run();
		};
	}
}

#endif