#pragma once
namespace Core
{
	struct Color
	{
		uint8_t red;
		uint8_t green;
		uint8_t blue;
		uint8_t alpha;

		const static Color RED;
		const static Color GREEN;
		const static Color BLUE;
		const static Color BLACK;
		const static Color WHITE;
	};
};