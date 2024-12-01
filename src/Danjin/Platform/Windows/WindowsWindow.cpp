#include <pch.h>
#include "WindowsWindow.hpp"

namespace Danjin {
static bool s_SDLInitialized = false;

Window *Window::create(const WindowProps &props) {
	return new WindowsWindow(props);
}

Window::~Window() {
}

WindowsWindow::WindowsWindow(const WindowProps &props) {
	init(props);
}

WindowsWindow::~WindowsWindow() {
	shutdown();
}

void WindowsWindow::onUpdate() {
	if (SDL_PollEvent(NULL) == 1)
		SDL_PollEvent(&m_event);
	SDL_GL_SwapWindow(m_window);
}

void WindowsWindow::setVSync(bool enabled) {
	if (enabled)
		SDL_GL_SetSwapInterval(1);
	else
		SDL_GL_SetSwapInterval(0);

	m_data.vSync = enabled;
}

bool WindowsWindow::isVSync() const {
	return m_data.vSync;
}


void WindowsWindow::init(const WindowProps &props) {
	m_data.title = props.title;
	m_data.width  = props.width;
	m_data.height = props.height;

	DANJIN_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);

	if (!s_SDLInitialized) {
		int success = SDL_Init(SDL_INIT_VIDEO);
		DANJIN_CORE_ASSERT(success, "Could not initialize SDL2");

		s_SDLInitialized = true;
	}

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	m_window = SDL_CreateWindow(
		props.title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		(int)props.width,
		(int)props.height,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	DANJIN_CORE_ASSERT(m_window, "Could not initialize SDL_Window");

	m_context = SDL_GL_CreateContext(m_window);
	DANJIN_CORE_ASSERT(m_context, "Could not initialize SDL_GL_Context");

	SDL_SetWindowData(m_window, "WindowData", &m_data);
	setVSync(true);
}

void WindowsWindow::shutdown() {
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}


}
