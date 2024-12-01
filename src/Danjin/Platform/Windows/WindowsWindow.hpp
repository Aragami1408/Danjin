#pragma once

#include <Danjin/Window.hpp>

#include <SDL2/SDL.h>

namespace Danjin {
class WindowsWindow : public Window {
public:
	WindowsWindow(const WindowProps &props);
	virtual ~WindowsWindow();

	void onUpdate() override;

	inline u32 getWidth() const override { return m_data.width; }
	inline u32 getHeight() const override { return m_data.height; }

	inline const void *getEvent() const override { return &m_event; }

	// Window attributes
	inline void setEventCallback(const EventCallbackFn &callback) override {
		m_data.eventCallback = callback;
	}
	void setVSync(bool enabled) override;
	bool isVSync() const override;

private:
	virtual void init(const WindowProps &props);
	virtual void shutdown();

private:
	SDL_Window *m_window;
	SDL_GLContext m_context;
	SDL_Event m_event;

	struct WindowData {
		std::string title;
		u32 width, height;
		bool vSync;
		EventCallbackFn eventCallback;
	};

	WindowData m_data;
};
}
