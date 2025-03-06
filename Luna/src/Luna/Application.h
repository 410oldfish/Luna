//
// Created by 47230 on 2025/3/5.
//
#pragma once
#include "Core.h"
#include "Window.h"
namespace Luna{
    class LUNA_API Application{
    public:
        Application();
        virtual ~Application();
        void Run();

    private:
        std::unique_ptr<Window> m_Window;
        bool m_Running = true;
    };

    //To be defined in Client
    Application* CreateApplication();

}
