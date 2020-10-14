#pragma once

#include "IPainter.h"

struct SDL_Renderer;

namespace Core
{
	class SDLPainter : public IPainter
	{
	public:
		SDLPainter(SDL_Renderer* renderer);
		virtual ~SDLPainter();

		virtual void DrawLine(const Vector2& v1, const Vector2& v2, int16_t pixelSize) override;

		virtual void DrawLines(const std::vector<Vector2>& points) override;

		virtual void DrawPoint(const Vector2& v) override;

		virtual void DrawPoints(const std::vector<Vector2>& points) override;

		virtual void DrawCircle(const std::vector<Vector2>& center, float radius) override;

		virtual void DrawFillCircle(const std::vector<Vector2>& center, float radius) override;

		virtual void DrawRectangle(float x, float y, float width, float height) override;

		virtual void DrawFillRectangle(float x, float y, float width, float height) override;

		virtual void SetColor(int8_t r, int8_t g, int8_t b, int8_t a) override;

		virtual void SetBlendMode(TBlendingMode mode) override;

		virtual void SetDrawScale(const Vector2& scale) override;

	private:
		SDL_Renderer* m_Renderer;
	};
}