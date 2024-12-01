#include <pch.h>
#include <Danjin/Application.hpp>

#include <Danjin/Logger.hpp>
#include <Danjin/Event/ApplicationEvent.hpp>

#include <SDL2/SDL.h>
#include <GL/glew.h>
namespace Danjin {
Application::Application() {
	m_window = std::unique_ptr<Window>(Window::create());
}

Application::~Application() {
}

void Application::run() {
	while(m_running) {
		SDL_Event *event = (SDL_Event *) m_window->getEvent();
		if (event->type == SDL_QUIT) {
			m_running = false;
		}
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		m_window->onUpdate();
	}
}
}
