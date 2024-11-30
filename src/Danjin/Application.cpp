#include <pch.h>
#include <Danjin/Application.hpp>

#include <Danjin/Logger.hpp>
#include <Danjin/Event/ApplicationEvent.hpp>


namespace Danjin {
Application::Application() {
}

Application::~Application() {
}

void Application::run() {
	WindowResizeEvent e(1280, 720);
	if (e.isInCategory(EventCategoryApplication))
		DANJIN_TRACE(e.toString());
	if (e.isInCategory(EventCategoryInput))
		DANJIN_TRACE(e.toString());
	while(true);
}
}
