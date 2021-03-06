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
	./src/Poor3D/Rendering/Light.cpp
	./src/Poor3D/Rendering/SpotLight.cpp
	./src/Poor3D/Rendering/Mesh.cpp
	./src/Poor3D/Rendering/RenderEngine.cpp
	./src/Poor3D/Rendering/Material.cpp
	./src/Poor3D/Rendering/PhongMaterial.cpp
	./src/Poor3D/Rendering/Texture.cpp
	./src/Poor3D/Rendering/ImageTexture.cpp
	./src/Poor3D/Rendering/DepthTexture.cpp
	./src/Poor3D/Rendering/FrameBuffer.cpp
	./src/Poor3D/Shader/Shader.cpp
	./src/Poor3D/Utils/ObjLoader.cpp
	./src/Poor3D/Utils/BMPLoader.cpp
	./src/Poor3D/Scene/Scene.cpp
	./src/Poor3D/Scene/SceneNode.cpp
	./src/Poor3D/Scene/Camera.cpp
	./src/Poor3D/Scene/WalkerCamera.cpp
)

add_library( glew ./lib/glew.c)

include_directories(./src ./include)
link_directories(./lib)
add_executable(Poor3D ${SOURCE})
TARGET_LINK_LIBRARIES(Poor3D glew)
if(WIN32)
	TARGET_LINK_LIBRARIES(Poor3D -static -lglfw3 -pthread -lopengl32)
else()
	TARGET_LINK_LIBRARIES(Poor3D -lglfw3 -pthread -lX11 -lXrandr -lXi -lXxf86vm -lXinerama -lXcursor -lGL)
endif()