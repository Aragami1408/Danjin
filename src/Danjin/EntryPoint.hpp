#pragma once

#ifdef DANJIN_PLATFORM_WINDOWS
extern Danjin::Application *Danjin::createApplication();
int main(int argc, char **argv) {
	Danjin::Logger::init();
	DANJIN_CORE_WARN("Warning from core");
	int a = 5;
	DANJIN_INFO("Hello! Var={0}", a);
	auto app = Danjin::createApplication();
	app->run();
	delete app;
}
#endif
