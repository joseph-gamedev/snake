#pragma once

namespace Core
{
	struct Color;

	template<typename T>
	struct  Rectangle;

	enum class TBlendingMode
	{
		kNone,
		kAlpha,
		kAdditive,
		kColorModulate
	};

	class IPainter
	{
	public:
		virtual ~IPainter() {}

		virtual void ClearColor(const Color& color) = 0;

		virtual void DrawString(void* font, const char* text, const Rectangle<int>& rect, const Color& color) = 0;

		virtual void DrawThickLine(const Vector2& v1, const Vector2& v2, float width) = 0;

		virtual void DrawLine(const Vector2& v1, const Vector2& v2) = 0;

		//virtual void DrawLines(const std::vector<Vector2>& points) = 0;

		virtual void DrawPoint(const Vector2& v) = 0;

		//virtual void DrawPoints(const std::vector<Vector2>& points) = 0;

		virtual void DrawCircle(const Vector2& center, float radius) = 0;

		virtual void DrawFillCircle(const Vector2& center, float radius) = 0;

		virtual void DrawRectangle(float x, float y, float width, float height) = 0;

		virtual void DrawFillRectangle(float x, float y, float width, float height) = 0;

		virtual void SetColor(int8_t r, int8_t g, int8_t b, int8_t a) = 0;

		virtual void SetColor(const Color& color) = 0;

		virtual void SetBlendMode(TBlendingMode mode) = 0;

		virtual void SetDrawScale(const Vector2& scale) = 0;

	};
};