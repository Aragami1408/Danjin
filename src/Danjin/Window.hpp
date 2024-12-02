#pragma once

#include <pch.h>

#include <Danjin/Common.h>
#include <Danjin/Event/Event.hpp>

namespace Danjin {
struct WindowProps {
	std::string title;
	u32 width;
	u32 height;

	WindowProps(const std::string &title = "Danmaku Engine", u32 width = 1280, u32 height = 720)
		: title(title), width(width), height(height) {}
};

// Interface representing a desktop system based Window
class DANJIN_API Window {
public:
	using EventCallbackFn = std::function<void(Event&)>;

	virtual ~Window();

	virtual void onUpdate() = 0;

	virtual u32 getWidth() const = 0;
	virtual u32 getHeight() const = 0;

	virtual const void *getEvent() const = 0;
	virtual const void *getNativeWindow() const = 0;

	virtual void setEventCallback(const EventCallbackFn &callback) = 0;
	virtual void setVSync(bool enabled) = 0;
	virtual bool isVSync() const = 0;

	static Window *create(const WindowProps &props = WindowProps());
};
}
