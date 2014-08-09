#ifndef CORE_COREENGINE_H_
#define CORE_COREENGINE_H_

#include <string>
#include <Poor3D/Core/Rendering/P3DWindow.h>
#include <Poor3D/Core/Game.h>
#include <Poor3D/Core/Input/P3DMouse.h>
#include <Poor3D/Core/Input/P3DKeyboard.h>

namespace Poor3D{
	namespace Core
	{
		class Game;
		
		class CoreEngine
		{
		public:
			CoreEngine(Game *game, double frameRate=60.0);
			~CoreEngine();

			const Input::P3DMouse *getMouse() const
			{ return mouse; }
			const Input::P3DKeyboard *getKeyboard() const
			{ return keybd; }

			const Rendering::P3DWindow *getWindow() const 
			{ return window; }
			void createWindow(int width, int height,
				const char *title);

			void start();
			void stop();
		private:
			double frameTime;
			int width, height;

			Rendering::P3DWindow *window; 
			Input::P3DMouse *mouse;
			Input::P3DKeyboard *keybd;
			Game *game;
			bool isRunning;

			void run();
		};
	}
}

#endif