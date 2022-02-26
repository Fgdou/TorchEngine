cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/glad)
add_subdirectory(lib/glfw)
add_subdirectory(lib/glm)

set(TORCH_INCLUDE src/Torch lib/glfw/include lib/glm/glm ${GLAD_INCLUDE_DIRS})
set(TORCH_LIB glfw glm glad)

set(SANDBOX_INCLUDE src/Torch)
set(SANDBOX_LIB TorchEngine)

project(TochEngine CXX)
file(GLOB_RECURSE TORCH_SRC src/Torch/*.cpp)
add_library(TorchEngine ${TORCH_SRC} lib/stb_image/stb_image.cpp lib/stb_image/stb_image.h)
target_include_directories(TorchEngine PUBLIC ${TORCH_INCLUDE})
target_link_libraries(TorchEngine ${TORCH_LIB})


project(Sandbox CXX)
file(GLOB_RECURSE SANDBOX_SRC src/Sandbox/*.cpp)
add_executable(Sandbox ${SANDBOX_SRC})
target_link_libraries(Sandbox ${SANDBOX_LIB})
target_include_directories(Sandbox PUBLIC ${SANDBOX_INCLUDE})