//
// Created by 47230 on 2025/3/10.
//

#pragma once

#include "Luna/Input.h"

namespace Luna {
	class WindowsInput : public Luna::Input {
	protected:
			virtual bool IsKeyPressedImpl(int keycode) override;
			virtual bool IsMouseButtonPressedImpl(int button) override;
			virtual std::pair<float, float> GetMousePositionImpl() override;
			virtual float GetMouseXImpl() override;
			virtual float GetMouseYImpl() override;
	};

}