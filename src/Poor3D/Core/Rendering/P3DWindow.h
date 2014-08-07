#ifndef CORE_P3DWINDOW_H_
#define CORE_P3DWINDOW_H_

#include <string>
#include <GLFW/glfw3.h>

namespace Poor3D
{
	namespace Core
	{
		namespace Rendering{
			class P3DWindow
			{
			public:
				P3DWindow(int width, int height, const char *title);
				~P3DWindow();

				//frequently used function
				void update();
				int getFPS() const { return FPS; }
				bool isCloseRequested() const;
				GLFWwindow *getHandler() const { return window; }

				void setTitle(const char *);
				void setSize(int width, int height);
				void makeCurrent() const;
				const char *getTitle() const { return title.c_str(); }
			private:
				int frames;
				int FPS;
				double lastFPSUpdate;
				int width, height;
				std::string title;
				GLFWwindow *window;
			};
		}
	}
}

#endif