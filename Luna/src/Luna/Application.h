//
// Created by 47230 on 2025/3/5.
//
#pragma once
#include "Core.h"
#include "Window.h"
#include "Luna/Events/ApplicationEvent.h"
#include "Luna/Events/Event.h"
#include "Luna/LayerStack.h"

namespace Luna{
    class LUNA_API Application{
    public:
        Application();
        virtual ~Application();
        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

    private:
        bool OnWindowClosed(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
        LayerStack m_LayerStack;
    };

    //To be defined in Client
    Application* CreateApplication();

}
