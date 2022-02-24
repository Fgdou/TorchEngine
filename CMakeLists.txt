cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 14)


project(TochEngine CXX)
file(GLOB_RECURSE TORCH_SRC src/Torch/*.cpp)
add_library(TorchEngine ${TORCH_SRC})
target_include_directories(TorchEngine PUBLIC src/Torch)


project(Sandbox CXX)
file(GLOB_RECURSE SANDBOX_SRC src/Sandbox/*.cpp)
add_executable(Sandbox ${SANDBOX_SRC})
target_link_libraries(Sandbox TorchEngine)
target_include_directories(Sandbox PUBLIC src/Torch)