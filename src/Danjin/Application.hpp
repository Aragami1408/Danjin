#pragma once

#include <Danjin/Common.h>
#include <Danjin/Event/Event.hpp>
#include <Danjin/Window.hpp>

namespace Danjin {
class DANJIN_API Application {
public:
	Application();
	virtual ~Application();

	void run();
private:
	std::unique_ptr<Window> m_window;
	bool m_running = true;
};
// NOTE(higanbana): defined in client
Application *createApplication();
}
