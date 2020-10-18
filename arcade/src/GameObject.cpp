#include "GameObject.h"

GameObject::GameObject()
	: m_Position(Vector2::Zero)
	, m_Size(Vector2::Zero)
{

}

GameObject::GameObject(const Vector2& position, const Vector2& size)
	: m_Position(position)
	, m_Size(size)
{

}

Vector2 GameObject::GetPosition()
{
	return m_Position;
}

void GameObject::SetPosition(const Vector2& position)
{
	m_Position = position;
}

Vector2 GameObject::GetSize()
{
	return m_Size;
}

