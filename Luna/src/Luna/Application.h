//
// Created by 47230 on 2025/3/5.
//
#pragma once
#include "Core.h"
#include "Window.h"
#include "Luna/Events/ApplicationEvent.h"
#include "Luna/Events/Event.h"
#include "Luna/LayerStack.h"
#include "Luna/ImGui/ImGuiLayer.h"

namespace Luna{
    class LUNA_API Application{
    public:
        Application();
        virtual ~Application();
        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* overlay);

        inline Window& GetWindow() { return *m_Window; }
        inline static Application& Get() { return *s_Instance; }
    private:
        bool OnWindowClosed(WindowCloseEvent& e);
        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;

        static Application* s_Instance;
    };

    //To be defined in Client
    Application* CreateApplication();

}
