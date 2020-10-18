#pragma once

class IInput
{
	public:

		virtual ~IInput() {}
	
		virtual Vector2 GetMousePosition() = 0;

		virtual const uint8_t* GetKeyboardState(int* numkeys) = 0;
};