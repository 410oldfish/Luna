//
// Created by 47230 on 2025/3/6.
//
#pragma once

#include "Event.h"

namespace Luna{
	class LUNA_API KeyEvent : public Event
	{
          public:
            inline int GetKeyCode() const {return m_KeyCode;}
            EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
          protected:
            KeyEvent(int keycode)
            	: m_KeyCode(keycode){}

            int m_KeyCode;

	};

    class LUNA_API KeyPressedEvent : public KeyEvent
	{
      public:
        KeyPressedEvent(int keycode, int repeatCount)
        	: KeyEvent(keycode), m_RepeatCount(repeatCount){}
        inline int GetRepeatCount() const {return m_RepeatCount;}

        std::string ToString() const override
        {
          	std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << "(" << m_RepeatCount << "repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed);

      private:
        int m_RepeatCount;
	};

    class LUNA_API KeyReleasedEvent : public KeyEvent
	{
      public:
        KeyReleasedEvent(int keycode)
        	: KeyEvent(keycode) {}
        std::string ToString() const override
        {
        	std::stringstream ss;
        	ss << "KeyReleasedEvent: " << m_KeyCode;
        	return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased);
	};

	class LUNA_API KeyTypedEvent : public KeyEvent {
	public:
		KeyTypedEvent(int keycode) : KeyEvent(keycode){}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEventEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped);
	};

}
