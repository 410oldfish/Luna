#include <Luna.h>

class ExampleLayer : public Luna::Layer {
public:
    ExampleLayer():Layer("Example") {

    }

    void OnUpdate() override {

    }

    void OnEvent(Luna::Event &event) override {
        if (event.GetEventType() == Luna::EventType::KeyPressed) {
            Luna::KeyPressedEvent& e = ( Luna::KeyPressedEvent&)event;

            if (e.GetKeyCode() == LUNA_KEY_TAB) {
                LUNA_TRACE("Tab pressed event");
            }

            LUNA_TRACE("{0}", (char)e.GetKeyCode());
        }
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