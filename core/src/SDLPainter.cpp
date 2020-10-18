#include "SDLPainter.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include "SDLPrimitives.h"

Core::SDLPainter::SDLPainter(SDL_Renderer * renderer)
	: m_Renderer(renderer)
{
}

Core::SDLPainter::~SDLPainter()
{

}

void Core::SDLPainter::ClearColor(const Color& color)
{
	SDL_SetRenderDrawColor(m_Renderer, color.red, color.green, color.blue, color.alpha);
	SDL_RenderClear(m_Renderer);
}

void Core::SDLPainter::DrawString(void * font, const char * text, const Rectangle<int> & rect, const Color& color)
{
	TTF_Font* sdl_font = static_cast<TTF_Font*>(font);
	if (sdl_font)
	{
		SDL_Surface* surfaceMessage = TTF_RenderText_Solid(sdl_font, text, SDL_Color{color.red, color.green,color.blue,color.alpha});
		SDL_Texture* message = SDL_CreateTextureFromSurface(m_Renderer, surfaceMessage);

		SDL_Rect sdlrect = { rect.topLeftX,rect.topLeftY, rect.width, rect.height };
		SDL_RenderCopy(m_Renderer, message, nullptr, &sdlrect);

		SDL_FreeSurface(surfaceMessage);
		SDL_DestroyTexture(message);
	}
}

void Core::SDLPainter::DrawThickLine(const Vector2 & v1, const Vector2 & v2, float width)
{
	uint8_t r, g, b, a;
	SDL_GetRenderDrawColor(m_Renderer ,&r ,&g ,&b ,&a);
	thickLineRGBA(m_Renderer, v1.X, v1.Y, v2.X, v2.Y, width, r, g, b, a);
}

void Core::SDLPainter::DrawLine(const Vector2 & v1, const Vector2 & v2)
{
	 SDL_RenderDrawLine(m_Renderer, v1.X , v1.Y , v2.X , v2.Y);
}

//void Core::SDLPainter::DrawLines(const std::vector<Vector2>& points)
//{
//
//}

void Core::SDLPainter::DrawPoint(const Vector2 & v)
{
	SDL_RenderDrawPoint(m_Renderer, v.X, v.Y);
}

//void Core::SDLPainter::DrawPoints(const std::vector<Vector2>& points)
//{
//}

void Core::SDLPainter::DrawCircle(const Vector2& center, float radius)
{
	uint8_t r, g, b, a;
	SDL_GetRenderDrawColor(m_Renderer, &r, &g, &b, &a);
	circleRGBA(m_Renderer,center.X, center.Y, radius, r, g, b, a );
}

void Core::SDLPainter::DrawFillCircle(const Vector2& center, float radius)
{
	uint8_t r, g, b, a;
	SDL_GetRenderDrawColor(m_Renderer, &r, &g, &b, &a);
	filledCircleRGBA(m_Renderer, center.X, center.Y, radius, r, g, b, a);
}

void Core::SDLPainter::DrawRectangle(float x, float y, float width, float height)
{
	SDL_Rect rect = { x,y,width,height };
	SDL_RenderDrawRect(m_Renderer, &rect);
}

void Core::SDLPainter::DrawFillRectangle(float x, float y, float width, float height)
{
	SDL_Rect rect = { x,y,width,height };
	SDL_RenderFillRect(m_Renderer, &rect);
}

void Core::SDLPainter::SetColor(int8_t r, int8_t g, int8_t b, int8_t a)
{
	SDL_SetRenderDrawColor(m_Renderer, r, g, b, a);
}

void Core::SDLPainter::SetColor(const Color & color)
{
	SetColor(color.red, color.green, color.blue, color.alpha);
}

void Core::SDLPainter::SetBlendMode(TBlendingMode mode)
{
	SDL_BlendMode blend_mode = (SDL_BlendMode)mode;
	SDL_SetRenderDrawBlendMode(m_Renderer, blend_mode);
}

void Core::SDLPainter::SetDrawScale(const Vector2 & scale)
{
	SDL_RenderSetScale(m_Renderer, scale.X, scale.Y);
}
