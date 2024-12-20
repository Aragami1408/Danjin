#include <pch.h>
#include <Danjin/Application.hpp>

#include <Danjin/Logger.hpp>

#include <SDL2/SDL.h>
#include <glad/glad.h>

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
		glClearColor(1.0f, 0, 1.0f, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		for (Layer *layer : m_layerStack)
			layer->onUpdate();
		m_window->onUpdate();
	}
}

void Application::onEvent(Event &e) {
	EventDispatcher dispatcher(e);
	dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowClose));

	for (auto it = m_layerStack.end(); it != m_layerStack.begin();) {
		(*--it)->onEvent(e);
		if (e.handled)
			break;
	}
}

void Application::pushLayer(Layer *layer) {
	m_layerStack.pushLayer(layer);
}

void Application::pushOverlay(Layer *layer) {
	m_layerStack.pushOverlay(layer); }

bool Application::onWindowClose(WindowCloseEvent &e) {
	m_running = false;
	return true;
}

}
