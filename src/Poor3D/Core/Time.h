#ifndef UTILS_TIME_H_
#define UTILS_TIME_H_

#include <GLFW/glfw3.h>

namespace Poor3D{
	namespace Core{
		inline double getTime()
		{
			return glfwGetTime();
		}
	}
}

#endif