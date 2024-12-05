#pragma once

#if defined(DANJIN_PLATFORM_WINDOWS) || defined(DANJIN_PLATFORM_APPLE)
extern Danjin::Application *Danjin::createApplication();
int main(int argc, char **argv) {
	Danjin::Logger::init();
	auto app = Danjin::createApplication();
	app->run();
	delete app;
}
#endif
