cmake_minimum_required(VERSION 3.5)

set(proj_name "OpenGL_Samples")
project(${proj_name})

# find all source files
file(GLOB srcs "srcs/*.cpp")
# find all header files
file(GLOB headers "srcs/*.h")
# find imgui source files
file(GLOB imgui_files "srcs/imgui/*.h" "srcs/imgui/*.cpp")

# add glad.c
set(srcs ${srcs} "thirdparty/glad/src/glad.c")

add_executable(${proj_name} ${srcs} ${headers} ${imgui_files})

# use C++17
target_compile_features(${proj_name} PRIVATE cxx_std_20)

# set GLFW and GLM libary
add_subdirectory("thirdparty/glm/" EXCLUDE_FROM_ALL)
add_subdirectory("thirdparty/glfw/" EXCLUDE_FROM_ALL)
target_link_libraries(${proj_name} 
    PRIVATE glm
    PRIVATE glfw
)

# set glad files
target_include_directories(${proj_name} PRIVATE "thirdparty/glad/include/")
target_include_directories(${proj_name} PRIVATE "thirdparty/")

# fix glm error
add_definitions(-D GLM_ENABLE_EXPERIMENTAL)