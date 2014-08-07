#ifndef CORE_COREENGINE_H_
#define CORE_COREENGINE_H_

#include <string>
#include <Poor3D/Core/Rendering/P3DWindow.h>
#include <Poor3D/Core/Game.h>

namespace Poor3D{
	namespace Core
	{
		class CoreEngine
		{
		public:
			CoreEngine(Game *game, double frameRate=60.0);
			~CoreEngine();

			void createWindow(int width, int height,
				const char *title);

			void start();
			void stop();
		private:
			double frameTime;
			int width, height;

			Rendering::P3DWindow *window; 
			Game *game;
			bool isRunning;

			void run();
		};
	}
}

#endif