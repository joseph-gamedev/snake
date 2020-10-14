#pragma once

#include "IRenderer.h"

struct SDL_Renderer;
struct SDL_Window;

namespace Core
{
	class SDLView;
	class SDLRenderer : public IRenderer
	{
	public:
		SDLRenderer(SDLView& sdlView);
		virtual ~SDLRenderer() {}

		virtual void Init() override;

		virtual void ClearColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) override;

		virtual void ReInitialize() override;

		virtual void SwapBuffers() override;

		virtual void Terminate() override;

		virtual void* Get() override;

	private:
		SDL_Renderer* m_Renderer;
		SDL_Window* m_Window;
	};
};