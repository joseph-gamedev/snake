#include "SDLPainter.h"
#include <SDL.h>

Core::SDLPainter::SDLPainter(SDL_Renderer * renderer)
	: m_Renderer(renderer)
{
}

Core::SDLPainter::~SDLPainter()
{

}

void Core::SDLPainter::DrawLine(const Vector2 & v1, const Vector2 & v2, int16_t pixelSize)
{
	SetDrawScale(Vector2::One * pixelSize);
	SDL_RenderDrawLine(m_Renderer, v1.X /(float)pixelSize, v1.Y / (float)pixelSize, v2.X / (float)pixelSize, v2.Y / (float)pixelSize);
	SetDrawScale(Vector2::One);
}

void Core::SDLPainter::DrawLines(const std::vector<Vector2>& points)
{

}

void Core::SDLPainter::DrawPoint(const Vector2 & v)
{
	SDL_RenderDrawPoint(m_Renderer, v.X, v.Y);
}

void Core::SDLPainter::DrawPoints(const std::vector<Vector2>& points)
{
}

void Core::SDLPainter::DrawCircle(const std::vector<Vector2>& center, float radius)
{
}

void Core::SDLPainter::DrawFillCircle(const std::vector<Vector2>& center, float radius)
{
}

void Core::SDLPainter::DrawRectangle(float x, float y, float width, float height)
{
	SDL_Rect rect = { x,y,width,height };
	SDL_RenderDrawRect(m_Renderer, &rect);
}

void Core::SDLPainter::DrawFillRectangle(float x, float y, float width, float height)
{
}

void Core::SDLPainter::SetColor(int8_t r, int8_t g, int8_t b, int8_t a)
{
	SDL_SetRenderDrawColor(m_Renderer, r, g, b, a);
}

void Core::SDLPainter::SetBlendMode(TBlendingMode mode)
{
}

void Core::SDLPainter::SetDrawScale(const Vector2 & scale)
{
	SDL_RenderSetScale(m_Renderer, scale.X, scale.Y);
}
