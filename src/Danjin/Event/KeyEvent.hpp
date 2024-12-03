#pragma once

#include <Danjin/Event/Event.hpp>

namespace Danjin {
class KeyEvent : public Event {
public:
	inline u32 getKeyCode() const { return m_keycode; }

	EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

protected:
	KeyEvent(u32 keycode) : m_keycode(keycode) {}

	u32 m_keycode;
};

class KeyPressedEvent : public KeyEvent {
public:
	KeyPressedEvent(u32 keycode, u8 repeatCount) : KeyEvent(keycode), m_repeatCount(repeatCount) {}

	inline int getRepeatCount() const { return m_repeatCount; }
	
	std::string toString() const override {
		std::stringstream ss;
		ss << "KeyPressedEvent: " << m_keycode << " (" << m_repeatCount << " repeats)";
		return ss.str();
	}

	EVENT_CLASS_TYPE(KeyPressed)

protected:
	u8 m_repeatCount;
};

class KeyReleasedEvent : public KeyEvent {
public:
	KeyReleasedEvent(u32 keycode) : KeyEvent(keycode) {}

	std::string toString() const override {
		std::stringstream ss;
		ss << "KeyReleasedEvent: " << m_keycode;
		return ss.str();
	}

	EVENT_CLASS_TYPE(KeyReleased);
};
}
