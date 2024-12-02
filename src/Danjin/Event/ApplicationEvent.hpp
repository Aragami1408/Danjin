#pragma once

#include <Danjin/Event/Event.hpp>

#include <sstream>

namespace Danjin {
class WindowResizeEvent : public Event {
public:
	WindowResizeEvent(u32 width, u32 height) : m_width(width), m_height(height) {}

	inline u32 getWidth() const { return m_width; }
	inline u32 getHeight() const { return m_height; }

	std::string toString() const override {
		std::stringstream ss;
		ss << "WindowResizeEvent: " << m_width << ", " << m_height;
		return ss.str();
	}

	EVENT_CLASS_TYPE(WindowResize)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)

private:
	u32 m_width, m_height;
};

class WindowCloseEvent : public Event {
public:
	WindowCloseEvent() = default;

	EVENT_CLASS_TYPE(WindowClose)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class AppTickEvent : public Event {
public:
	AppTickEvent() = default;

	EVENT_CLASS_TYPE(AppTick)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class AppUpdateEvent : public Event {
public:
	AppUpdateEvent() = default;

	EVENT_CLASS_TYPE(AppUpdate)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};

class AppRenderEvent : public Event {
public:
	AppRenderEvent() = default;

	EVENT_CLASS_TYPE(AppRender)
	EVENT_CLASS_CATEGORY(EventCategoryApplication)
};
}

