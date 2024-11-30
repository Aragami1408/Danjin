#pragma once

#ifdef DANJIN_PLATFORM_WINDOWS
extern Danjin::Application *Danjin::createApplication();
int main(int argc, char **argv) {
	Danjin::Logger::init();
	auto app = Danjin::createApplication();
	app->run();
	delete app;
}
#endif
