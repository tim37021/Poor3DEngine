cmake_minimum_required (VERSION 2.6)
project (Poor3D)
find_package(OpenGL)

set(CMAKE_CXX_FLAGS "-g -std=c++0x -Wall -DGLEW_STATIC -fvar-tracking")
set(CMAKE_C_FLAGS "-g -DGLEW_STATIC")

set(SOURCE
  ./src/Poor3D/Math/Mat4.cpp
	./src/Test/test.cpp
	./src/Poor3D/Core/CoreEngine.cpp
	./src/Poor3D/Window/P3DWindow.cpp
	./src/Poor3D/Window/P3DMouse.cpp
	./src/Poor3D/Window/P3DKeyboard.cpp
	./src/Poor3D/Rendering/Mesh.cpp
	./src/Poor3D/Rendering/RenderEngine.cpp
	./src/Poor3D/Shader/Shader.cpp
	./src/Poor3D/Utils/ObjLoader.cpp
	./src/Poor3D/Scene/Camera.cpp
	./src/Poor3D/Scene/WalkerCamera.cpp
)

add_library( glew ./lib/glew.c)

include_directories(./src ./include)
add_executable(Poor3D ${SOURCE})
TARGET_LINK_LIBRARIES(Poor3D glew)
TARGET_LINK_LIBRARIES(Poor3D -lglfw3 -pthread -lX11 -lXrandr -lXi -lXxf86vm -lXinerama -lXcursor -lGL)
