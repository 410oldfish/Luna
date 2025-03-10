#include <Luna.h>

class ExampleLayer : public Luna::Layer {
public:
    ExampleLayer():Layer("Example") {

    }

    void OnUpdate() override {
        LUNA_INFO("ExampleLayer::Update");
    }

    void OnEvent(Luna::Event &event) override {
        LUNA_TRACE("{0}", event.ToString());
    }
};

class SandBox : public Luna::Application {
public:
    SandBox() {
        PushLayer(new ExampleLayer());
        PushOverlay(new Luna::ImGuiLayer());
    }
    ~SandBox(){}
};

Luna::Application* Luna::CreateApplication() {
    return new SandBox();
}