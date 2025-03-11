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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

		void Begin();
		void End();

      private:
		float m_Time = 0.0f;
	};
}