#pragma once

namespace Core
{
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

		virtual void DrawLine(const Vector2& v1, const Vector2& v2, int16_t pixelSize) = 0;

		virtual void DrawLines(const std::vector<Vector2>& points) = 0;

		virtual void DrawPoint(const Vector2& v) = 0;

		virtual void DrawPoints(const std::vector<Vector2>& points) = 0;

		virtual void DrawCircle(const std::vector<Vector2>& center, float radius) = 0;

		virtual void DrawFillCircle(const std::vector<Vector2>& center, float radius) = 0;

		virtual void DrawRectangle(float x, float y, float width, float height) = 0;

		virtual void DrawFillRectangle(float x, float y, float width, float height) = 0;

		virtual void SetColor(int8_t r, int8_t g, int8_t b, int8_t a) = 0;

		virtual void SetBlendMode(TBlendingMode mode) = 0;

		virtual void SetDrawScale(const Vector2& scale) = 0;

	};
};