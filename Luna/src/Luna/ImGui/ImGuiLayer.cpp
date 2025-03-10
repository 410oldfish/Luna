//
// Created by 47230 on 2025/3/7.
//

#include "LunaPch.h"
#include "ImGuiLayer.h"

#include "Luna/Application.h"

#include "imgui.h"
#include "Platform/OpenGL/ImGuiOpenGLRender.h"
#include "Platform/OpenGL/imgui_impl_glfw.h"
#include "Platform/Windows/WindowsWindow.h"
//Temporary
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Luna{
	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer")
	{

	}

	ImGuiLayer::~ImGuiLayer() {
	}

	void ImGuiLayer::OnAttach(Window* window) {
		ImGui::CreateContext();
		ImGui::StyleColorsDark();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

		// io.AddKeyEvent(ImGuiKey_Tab, true);
		// io.AddKeyEvent(ImGuiKey_LeftArrow, true);
		// io.AddKeyEvent(ImGuiKey_RightArrow, true);
		// io.AddKeyEvent(ImGuiKey_UpArrow, true);
		// io.AddKeyEvent(ImGuiKey_DownArrow, true);
		// io.AddKeyEvent(ImGuiKey_PageUp, true);
		// io.AddKeyEvent(ImGuiKey_PageDown, true);
		// io.AddKeyEvent(ImGuiKey_Home, true);
		// io.AddKeyEvent(ImGuiKey_End, true);
		// io.AddKeyEvent(ImGuiKey_Insert, true);
		// io.AddKeyEvent(ImGuiKey_Delete, true);
		// io.AddKeyEvent(ImGuiKey_Backspace, true);
		// io.AddKeyEvent(ImGuiKey_Space, true);
		// io.AddKeyEvent(ImGuiKey_Enter, true);
		// io.AddKeyEvent(ImGuiKey_Escape, true);
		// io.AddKeyEvent(ImGuiKey_A, true);
		// io.AddKeyEvent(ImGuiKey_C, true);
		// io.AddKeyEvent(ImGuiKey_V, true);
		// io.AddKeyEvent(ImGuiKey_X, true);
		// io.AddKeyEvent(ImGuiKey_Y, true);
		// io.AddKeyEvent(ImGuiKey_Z, true);

		ImGui_ImplOpenGL3_Init("#version 410");
		ImGui_ImplGlfw_InitForOpenGL( static_cast<GLFWwindow*>(window->GetNativeWindow()), true);
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
		EventDispatcher dispatcher(event);
		//dispatcher.Dispatch<MouseButtonPressedEvent>(LUNA_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
		//dispatcher.Dispatch<MouseButtonReleasedEvent>(LUNA_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
		//dispatcher.Dispatch<MouseMovedEvent>(LUNA_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
		//dispatcher.Dispatch<MouseScrolledEvent>(LUNA_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
		//dispatcher.Dispatch<KeyPressedEvent>(LUNA_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
		//dispatcher.Dispatch<KeyReleasedEvent>(LUNA_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
		//dispatcher.Dispatch<WindowResizeEvent>(LUNA_BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));
		//dispatcher.Dispatch<KeyTypedEvent>(LUNA_BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
	}

	bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent &e) {
		ImGuiIO& io = ImGui::GetIO();
		io.AddMouseButtonEvent(e.GetMouseButton(), true);
		return false;
	}

	bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent &e) {
		ImGuiIO& io = ImGui::GetIO();
		io.AddMouseButtonEvent(e.GetMouseButton(), false);
		return false;
	}

	bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent &e) {
		ImGuiIO& io = ImGui::GetIO();
		io.AddMousePosEvent(e.GetX(), e.GetY());
		return false;
	}

	bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent &e) {
		ImGuiIO& io = ImGui::GetIO();
		io.AddMouseWheelEvent(e.GetXOffset(), e.GetYOffset());
		return false;
	}

	// bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent &e) {
	// 	ImGuiIO& io = ImGui::GetIO();
	// 	io.AddKeyEvent(static_cast<ImGuiKey>(e.GetKeyCode()), true);
	// 	return false;
	// }
	//
	// bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent &e) {
	// 	ImGuiIO& io = ImGui::GetIO();
	// 	io.AddKeyEvent(static_cast<ImGuiKey>(e.GetKeyCode()), false);
	// 	return false;
	// }

	bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent &e) {
		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
		glViewport(0, 0, e.GetWidth(), e.GetHeight());
		return false;
	}

	bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& e) {
		ImGuiIO& io = ImGui::GetIO();
		int keycode = e.GetKeyCode();
		if (keycode > 0 && keycode < 0x10000)
			io.AddInputCharacter((unsigned short)keycode);
		return false;
	}
}

