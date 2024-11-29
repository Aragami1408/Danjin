#include <Danjin.h>

class Sandbox : public Danjin::Application {
public:
	Sandbox() {}
	~Sandbox() {}
};

Danjin::Application *Danjin::createApplication() {
	return new Sandbox();
}
