#pragma once 

namespace Core
{
	template<typename T>
	struct  Rectangle
	{
		T topLeftX;
		T topLeftY;
		T width;
		T height;

		Vector2 GetSize();
		Vector2 GetCenter();

		bool Contains(const Vector2& point);
		bool Overlaps(const Rectangle<T>& other);

	};
	template<typename T>
	inline Vector2 Rectangle<T>::GetSize()
	{
		return Vector2(width,height);
	}
	template<typename T>
	inline Vector2 Rectangle<T>::GetCenter()
	{
		return Vector2(x + (width/2), y + (height/2));
	}
	template<typename T>
	inline bool Rectangle<T>::Contains(const Vector2& point)
	{
		return point.X >= topLeftX && point.X <= (topLeftX + width) &&  point.Y >= topLeftY && point.Y <= (topLeftY + height);
	}
	template<typename T>
	inline bool Rectangle<T>::Overlaps(const Rectangle<T>& other)
	{
		Vector2 topLeft1 = Vector2(topLeftX, topLeftY);
		Vector2 bottomRight1 = topLeft1 + GetSize();

		Vector2 topLeft2 = Vector2(other.topLeftX, other.topLeftY);
		Vector2 bottomRight2 = topLeft2 + other.GetSize();

		if (topLeft1.X >= bottomRight2.X || topLeft2.X > = bottomRight1.X)
			return false;

		if (topLeft1.Y >= bottomRight2.Y || topLeft2.Y >= bottomRight1.Y)
			return false;

		return true;
	}

	using Recti = Rectangle<int>;
	using Rectf = Rectangle<float>;
};