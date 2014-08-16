#ifndef CORE_GAME_H_
#define CORE_GAME_H_

#include <Poor3D/Core/CoreEngine.h>

namespace Poor3D
{
	namespace Core
	{
		class CoreEngine;
		class Game
		{
		public:
			virtual void render() = 0;
			virtual void update() = 0;
			virtual void buildScene() = 0;

			void setEngine(CoreEngine *e)
			{ engine = e; }
		protected:
			CoreEngine *engine;
		};
	}
}

#endif