cmake_minimum_required(VERSION 3.15)
project(Danjin VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(DANJIN_EXPORT)

option(BUILD_EXAMPLES "Build examples" OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include_directories(src)
include_directories(submodules)
include_directories(submodules/spdlog/include)

find_package(SDL2 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm CONFIG REQUIRED)

add_library(${PROJECT_NAME} SHARED
	src/Danjin/Application.cpp
	src/Danjin/Layer.cpp
	src/Danjin/LayerStack.cpp
	src/Danjin/Logger.cpp
	src/Danjin/Platform/Windows/WindowsWindow.cpp

	submodules/glad/glad.c

	submodules/imgui/imgui.cpp
	submodules/imgui/imgui_demo.cpp
	submodules/imgui/imgui_draw.cpp
	submodules/imgui/imgui_tables.cpp
	submodules/imgui/imgui_widgets.cpp

	submodules/imgui/imgui_impl_sdl2.cpp
	submodules/imgui/imgui_impl_opengl3.cpp
)

target_include_directories(${PROJECT_NAME}
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

# FUCK YOU MSVC
# target_precompile_headers(${PROJECT_NAME} PRIVATE src/pch.h)

target_link_libraries(${PROJECT_NAME}
	PUBLIC
		SDL2::SDL2
		SDL2::SDL2main
		OpenGL::GL
	PRIVATE
		glm::glm
)

if(BUILD_EXAMPLES)
	add_subdirectory(examples)
endif()

