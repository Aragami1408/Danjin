#pragma once

#include <Danjin/Common.h>
#include <Danjin/LayerStack.hpp>
#include <Danjin/Event/Event.hpp>
#include <Danjin/Event/ApplicationEvent.hpp>
#include <Danjin/Window.hpp>

namespace Danjin {
class DANJIN_API Application {
public:
	Application();
	virtual ~Application();

	void run();

	void onEvent(Event &e);
	void pushLayer(Layer *layer);
	void pushOverlay(Layer *layer);
private:
	bool onWindowClose(WindowCloseEvent &e);

	std::unique_ptr<Window> m_window;
	bool m_running = true;
	LayerStack m_layerStack;
};
// NOTE(higanbana): defined in client
Application *createApplication();
}
