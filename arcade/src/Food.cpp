#include  "Food.h"
#include <ArcadeCore.h>

Food::Food(const Vector2& position, const Vector2& size)
	: GameObject(position, size)
{

}

Food::Food()
	:GameObject(Vector2::Zero, Vector2::Zero)
{

}

Food::~Food()
{

}

void Food::Draw(Core::IPainter* painter)
{
	painter->SetColor(Core::Color::RED);
	painter->DrawFillRectangle(m_Position.X, m_Position.Y, m_Size.X, m_Size.Y);
}

