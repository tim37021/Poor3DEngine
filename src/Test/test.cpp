#include <Poor3D/Core/CoreEngine.h>

using namespace Poor3D::Core;

int main(int argc, char *argv[])
{
	CoreEngine engine(60.0);

	engine.createWindow(800, 600, "Default");

	engine.start();
	return 0;
}