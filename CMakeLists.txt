cmake_minimum_required (VERSION 2.6)
project (Poor3D)
find_package(OpenGL)

set(CMAKE_CXX_FLAGS "-g -std=c++0x")
set(CMAKE_LINK_FLAGS)


set(SOURCE
	./src/Test/test.cpp
	./src/Poor3D/Core/CoreEngine.cpp
	./src/Poor3D/Window/P3DWindow.cpp
	./src/Poor3D/Core/Input/P3DMouse.cpp
	./src/Poor3D/Core/Input/P3DKeyboard.cpp
)

include_directories(./src)
add_executable(Poor3D ${SOURCE})
TARGET_LINK_LIBRARIES(Poor3D -lglfw3 -lopengl32)