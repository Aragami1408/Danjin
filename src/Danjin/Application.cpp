#include <pch.h>
#include <Danjin/Application.hpp>

#include <Danjin/Logger.hpp>

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
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		m_window->onUpdate();
	}
}

void Application::onEvent(Event &e) {
	EventDispatcher dispatcher(e);
	dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowClose));
	DANJIN_CORE_TRACE("{0}", e.toString());
}

bool Application::onWindowClose(WindowCloseEvent &e) {
	m_running = false;
	return true;
}

}
