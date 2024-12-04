#include <Danjin.h>

class ExampleLayer : public Danjin::Layer {
public:
	ExampleLayer() : Layer("Example") {}

	void onUpdate() override {
		DANJIN_INFO("ExampleLayer::update");
	}

	void onEvent(Danjin::Event &event) override {
		DANJIN_TRACE("{0}", event.toString());
	}
};

class Sandbox : public Danjin::Application {
public:
	Sandbox() {
		// pushLayer(new ExampleLayer());
	}
	~Sandbox() {}
};

Danjin::Application *Danjin::createApplication() {
	return new Sandbox();
}
