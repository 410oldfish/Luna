#include <Luna.h>

class SandBox : public Luna::Application {
public:
    SandBox(){}
    ~SandBox(){}
};

Luna::Application* Luna::CreateApplication() {
    return new SandBox();
}