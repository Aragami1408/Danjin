#include <pch.h>
#include "WindowsWindow.hpp"

#include <Danjin/Event/ApplicationEvent.hpp>
#include <Danjin/Event/MouseEvent.hpp>
#include <Danjin/Event/KeyEvent.hpp>
#include <Danjin/Event/Event.hpp>

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
	processEvents();
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
		u32 success = SDL_Init(SDL_INIT_VIDEO);
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
		(u32)props.width,
		(u32)props.height,
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	DANJIN_CORE_ASSERT(m_window, "Could not initialize SDL_Window");

	m_glContext = SDL_GL_CreateContext(m_window);
	DANJIN_CORE_ASSERT(m_glContext, "Could not initialize SDL_GL_Context");
	setVSync(true);

}

void WindowsWindow::shutdown() {
	SDL_GL_DeleteContext(m_glContext);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

void WindowsWindow::processEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_WINDOWEVENT: {
				if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
					i32 newWidth = event.window.data1;
					i32 newHeight = event.window.data2;
					WindowResizeEvent e(newWidth, newHeight);
					m_data.width = newWidth;
					m_data.height = newHeight;
					m_data.eventCallback(e);
					break;
				}
				else if (event.window.event == SDL_WINDOWEVENT_CLOSE) {
					WindowCloseEvent e;
					m_data.eventCallback(e);
				}
				break;
			}
			case SDL_KEYDOWN: {
				u8 repeatCount = event.key.repeat;
				u32 keycode = event.key.keysym.sym;
				KeyPressedEvent e(keycode, repeatCount);
				m_data.eventCallback(e);
				break;
			}
			case SDL_KEYUP: {
				u32 keycode = event.key.keysym.sym;
				KeyReleasedEvent e(keycode);
				m_data.eventCallback(e);
				break;
			}
			case SDL_MOUSEMOTION: {
				float x = static_cast<float>(event.motion.x);
				float y = static_cast<float>(event.motion.y);
				MouseMovedEvent e(x, y);
				m_data.eventCallback(e);
				break;
			}
			case SDL_MOUSEWHEEL: {
				float x = event.wheel.preciseX;
				float y = event.wheel.preciseY;
				MouseScrolledEvent e(x, y);
				m_data.eventCallback(e);
				break;
			}
			case SDL_MOUSEBUTTONDOWN: {
				MouseButtonPressedEvent e(event.button.button);
				m_data.eventCallback(e);
				break;
			}
			case SDL_MOUSEBUTTONUP: {
				MouseButtonReleasedEvent e(event.button.button);
				m_data.eventCallback(e);
				break;
			}
			case SDL_QUIT: {
				WindowCloseEvent e;
				m_data.eventCallback(e);
				break;
			}
		}
	}
}

}
