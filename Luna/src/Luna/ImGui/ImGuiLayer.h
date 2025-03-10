//
// Created by 47230 on 2025/3/7.
//

#pragma once
#include "Luna/Layer.h"

namespace Luna{
	class LUNA_API ImGuiLayer : public Layer{
      public:
        ImGuiLayer();
        ~ImGuiLayer();

		void OnAttach() override;
		void OnDetach() override;
        void OnUpdate();
        void OnEvent(Event& event);

      private:
		float m_Time = 0.0f;
		float m_DeltaTime = 0.0f;
	};
}