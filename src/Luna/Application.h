//
// Created by 47230 on 2025/3/5.
//

#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"

namespace Luna{
    class LUNA_API Application{
    public:
        Application();
        virtual ~Application();
        void Run();
    };

    //To be defined in Client
    Application* CreateApplication();

}

#endif //APPLICATION_H
