//
// Created by 47230 on 2025/3/6.
//

#pragma once

#include "Luna/Core.h"
#include "Luna/Events/Event.h"
#include "Luna/Window.h"
namespace Luna{

    class LUNA_API Layer
    {
      public:
          Layer(const std::string& name = "Layer");
          virtual ~Layer();

          virtual void OnAttach() {}
          virtual void OnDetach() {}
          virtual void OnUpdate() {}
    	  virtual void OnImGuiRender(){}
          virtual void OnEvent(Event& event) {}

          inline const std::string& GetName() const { return m_DebugName; }
    protected:
          std::string m_DebugName;
    };
}