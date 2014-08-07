#ifndef CORE_COREENGINE_H_
#define CORE_COREENGINE_H_

#include <string>
#include <Poor3D/Core/Rendering/P3DWindow.h>
#include <Poor3D/Core/Game.h>
#include <Poor3D/Core/Input/P3DMouse.h>

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

			void createWindow(int width, int height,
				const char *title);

			void start();
			void stop();
		private:
			double frameTime;
			int width, height;

			Rendering::P3DWindow *window; 
			Input::P3DMouse *mouse;
			Game *game;
			bool isRunning;

			void run();
		};
	}
}

#endif