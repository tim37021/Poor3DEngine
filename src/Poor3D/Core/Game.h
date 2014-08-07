#ifndef CORE_GAME_H_
#define CORE_GAME_H_

namespace Poor3D
{
	namespace Core
	{
		class Game
		{
		public:
			virtual void render() = 0;
			virtual void update() = 0;
		};
	}
}

#endif