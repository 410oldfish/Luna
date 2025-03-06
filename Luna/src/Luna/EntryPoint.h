//
// Created by 47230 on 2025/3/5.
//
#pragma once
#ifdef LUNA_PLATFORM_WINDOWS

extern Luna::Application* Luna::CreateApplication();

int main(int argc, char** argv)
{
	Luna::Log::Init();
	LUNA_CORE_WARN("Initialized Log!");
	LUNA_INFO("Hello!");

	auto app = Luna::CreateApplication();
	app->Run();
	delete app;
}

#endif
