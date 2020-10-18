#include "SDLInput.h"
#include <SDL.h>

Vector2 SDLInput::GetMousePosition()
{
	int x, y;
	SDL_GetMouseState(&x,&y);
	return Vector2(x,y);
}

const uint8_t* SDLInput::GetKeyboardState(int* numkeys)
{
	return SDL_GetKeyboardState(numkeys);
}
