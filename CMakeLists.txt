cmake_minimum_required(VERSION 3.5)

set(proj_name "OpenGL_Samples")
project(${proj_name})

# find all source files
file(GLOB srcs "srcs/*.cpp")
# find all header files
file(GLOB headers "srcs/*.h")

add_executable(${proj_name} ${srcs} ${headers})

# use C++17
target_compile_features(${proj_name} PRIVATE cxx_std_17)
