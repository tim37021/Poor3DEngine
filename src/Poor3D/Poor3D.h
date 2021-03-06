#ifndef POOR3D_H_
#define POOR3D_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <Poor3D/Core/Core.h>
#include <Poor3D/Math/Math.h>
#include <Poor3D/Rendering/Rendering.h>
#include <Poor3D/Scene/Scene.h>
#include <Poor3D/Shader/Shader.h>
#include <Poor3D/Utils/Utils.h>

namespace Poor3D
{
	template <class Class, typename T>
	inline bool	instanceof(T const &object)
	{
		return dynamic_cast<Class const *>(&object);
	}
}

#endif
