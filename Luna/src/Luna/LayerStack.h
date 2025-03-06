//
// Created by 47230 on 2025/3/6.
//

#pragma once

#include "Luna/Core.h"
#include "Layer.h"
#include <vector>

namespace Luna{
	class LUNA_API LayerStack
    {
          public:
            LayerStack();
            ~LayerStack();

            void PushLayer(Layer* layer);
            void PushOverlay(Layer* overlay);
            void PopLayer(Layer* layer);
            void PopOverlay(Layer* overlay);

            std::vector<Layer*>::iterator begin() { return m_Layers.begin();}
			std::vector<Layer*>::iterator end() { return m_Layers.end();}

          private:
            std::vector<Layer*> m_Layers;
            std::vector<Layer*>::iterator m_LayerInsert;
    };
}