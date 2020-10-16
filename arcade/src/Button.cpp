#include "Button.h"

using namespace Core;

Button::Button(Vector2 & position, Vector2 & size)
	: Widget(position, size)
	, m_PaintColor(Color::BLUE)
{
}

void Button::Draw(Core::IPainter * painter)
{
	painter->SetColor(m_PaintColor);
	painter->DrawFillRectangle(m_Position.X, m_Position.Y, m_widgetBounds.width , m_widgetBounds.height);
}

void Button::Update(float deltaTime)
{
}

void Button::OnMouseEnter(Vector2 & position)
{
	m_PaintColor = m_ButtonData.m_HoverColor;
}

void Button::OnMouseLeave(Vector2 & position)
{
	m_PaintColor = m_ButtonData.m_NormalColor;
}

void Button::OnMouseMove(Vector2 & position)
{
}

void Button::OnMouseDown(Vector2 & position, int btnId, int clickCount)
{
	m_PaintColor = Color::RED;
	if (m_PressedEvent)
	{
		m_PressedEvent();
	}
}

void Button::OnMouseUp(Vector2 & position, int btnId, int clickCount)
{
	m_PaintColor = Color::BLUE;
}

void Button::RegisterBtnEvent(const ButtonEvent & btnEvent)
{
	m_PressedEvent = btnEvent;
}
