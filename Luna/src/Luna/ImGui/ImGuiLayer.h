//
// Created by 47230 on 2025/3/7.
//

#pragma once
#include "Luna/Events/KeyEvent.h"
#include "Luna/Events/MouseEvent.h"
#include "Luna/Events/ApplicationEvent.h"
#include "Luna/Layer.h"

namespace Luna{
	class LUNA_API ImGuiLayer : public Layer{
      public:
        ImGuiLayer();
        ~ImGuiLayer();

		void OnAttach(Window* window = nullptr) override;
		void OnDetach() override;
        void OnUpdate();
        void OnEvent(Event& event);

	private:
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrolledEvent(MouseScrolledEvent& e);
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnKeyTypedEvent(KeyTypedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent& e);

      private:
		float m_Time = 0.0f;
		float m_DeltaTime = 0.0f;
	};
}