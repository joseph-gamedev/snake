#pragma once

class IInput
{
	public:

		virtual ~IInput() {}
	
		virtual Vector2 GetMousePosition() = 0;

};