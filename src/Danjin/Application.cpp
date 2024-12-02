#include <pch.h>
#include <Danjin/Application.hpp>

#include <Danjin/Logger.hpp>
#include <Danjin/Event/ApplicationEvent.hpp>

#include <SDL2/SDL.h>
#include <GL/glew.h>
namespace Danjin {
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

Application::Application() {
	m_window = std::unique_ptr<Window>(Window::create());
	m_window->setEventCallback(BIND_EVENT_FN(Application::onEvent));
}

Application::~Application() {
}

void Application::run() {
	while(m_running) {
		SDL_Event *event = (SDL_Event *) m_window->getEvent();
		switch (event->type) {
			case SDL_QUIT:
				m_running = false;
				break;
			case SDL_WINDOWEVENT:
				if (event->window.event == SDL_WINDOWEVENT_RESIZED) {
					// TODO(higanbana): Handle window resize event here
				}
				break;
		}
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		m_window->onUpdate();
	}
}

void Application::onEvent(Event &e) {
	DANJIN_CORE_INFO("{0}", e.toString());
}

}
