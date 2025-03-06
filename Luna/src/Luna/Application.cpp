//
// Created by 47230 on 2025/3/5.
//
#include "lunaPch.h"
#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Luna{
	Application::Application(){}
	Application::~Application() {

	}

    void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		LUNA_TRACE(e.ToString());
      	while(true);
    }
}
