//
// Created by 47230 on 2025/3/7.
//

#include "LunaPch.h"
#include "ImGuiLayer.h"

#include "Luna/Application.h"

#include "imgui.h"
#include "Platform/OpenGL/ImGuiOpenGLRender.h"
#include "GLFW/glfw3.h"

namespace Luna{
	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer")
	{

	}

	ImGuiLayer::~ImGuiLayer() {
	}

	void ImGuiLayer::OnAttach() {
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		io.AddKeyEvent(ImGuiKey_Tab, true);
		io.AddKeyEvent(ImGuiKey_LeftArrow, true);
		io.AddKeyEvent(ImGuiKey_RightArrow, true);
		io.AddKeyEvent(ImGuiKey_UpArrow, true);
		io.AddKeyEvent(ImGuiKey_DownArrow, true);
		io.AddKeyEvent(ImGuiKey_PageUp, true);
		io.AddKeyEvent(ImGuiKey_PageDown, true);
		io.AddKeyEvent(ImGuiKey_Home, true);
		io.AddKeyEvent(ImGuiKey_End, true);
		io.AddKeyEvent(ImGuiKey_Insert, true);
		io.AddKeyEvent(ImGuiKey_Delete, true);
		io.AddKeyEvent(ImGuiKey_Backspace, true);
		io.AddKeyEvent(ImGuiKey_Space, true);
		io.AddKeyEvent(ImGuiKey_Enter, true);
		io.AddKeyEvent(ImGuiKey_Escape, true);
		io.AddKeyEvent(ImGuiKey_A, true);
		io.AddKeyEvent(ImGuiKey_C, true);
		io.AddKeyEvent(ImGuiKey_V, true);
		io.AddKeyEvent(ImGuiKey_X, true);
		io.AddKeyEvent(ImGuiKey_Y, true);
		io.AddKeyEvent(ImGuiKey_Z, true);

		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::OnDetach() {
		Layer::OnDetach();
	}

	void ImGuiLayer::OnUpdate() {
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
		m_Time = time;

		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	}

	void ImGuiLayer::OnEvent(Event &event) {
		Layer::OnEvent(event);
	}
}

