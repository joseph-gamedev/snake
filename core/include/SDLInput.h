#pragma once

#include "IInput.h"

class SDLInput : public IInput
{
public:

	virtual ~SDLInput() {}

	virtual Vector2 GetMousePosition() override;

	virtual const uint8_t* GetKeyboardState(int* numkeys) override;
};