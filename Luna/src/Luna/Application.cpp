//
// Created by 47230 on 2025/3/5.
//
#include "lunaPch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include <GLFW/glfw3.h>

namespace Luna{
	Application::Application() {
		m_Window = std::unique_ptr<Window>( Window::Create() );
	}
	Application::~Application() {

	}

    void Application::Run()
	{
      	while(m_Running) {
      		glClearColor(1, 0, 1, 1);
      		glClear(GL_COLOR_BUFFER_BIT);
      		m_Window->OnUpdate();
      	}
    }
}
