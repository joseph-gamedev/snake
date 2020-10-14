#include "SDLRenderer.h"
#include "SDLView.h"
#include <SDL.h>

Core::SDLRenderer::SDLRenderer(SDLView & sdlView)
{
	m_Renderer = SDL_CreateRenderer(static_cast<SDL_Window*>(sdlView.GetWindow()), -1, SDL_RENDERER_ACCELERATED);
}

void Core::SDLRenderer::Init()
{
}

void Core::SDLRenderer::ClearColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	SDL_SetRenderDrawColor(m_Renderer, r, g, b, a);
	SDL_RenderClear(m_Renderer);
}

void Core::SDLRenderer::ReInitialize()
{
}

void Core::SDLRenderer::SwapBuffers()
{
	SDL_RenderPresent(m_Renderer);
}

void Core::SDLRenderer::Terminate()
{
	if (m_Renderer)
	{
		SDL_DestroyRenderer(m_Renderer);
	}
}

void * Core::SDLRenderer::Get()
{
	return m_Renderer;
}