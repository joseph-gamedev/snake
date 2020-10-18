#include "SnakeNode.h"
#include <ArcadeCore.h>

SnakeNode::SnakeNode(const Vector2& position, const Vector2& size)
	: GameObject(position, size)
	, m_IsHead(false)
	, m_Direction(Vector2(0, -1 *size.Y))
	, m_PrevPosition(position)
{

}

SnakeNode::~SnakeNode()
{
}

void SnakeNode::Draw(Core::IPainter* painter)
{
	painter->SetColor(Core::Color::GREEN);
	painter->DrawRectangle(m_Position.X, m_Position.Y, m_Size.X, m_Size.Y);
}

void SnakeNode::Update(float deltaTime)
{
	//m_Position += m_Direction * deltaTime;
	//m_PrevPosition = m_Position;
}

void SnakeNode::SetAsHead(bool isHead)
{
	m_IsHead = isHead;
}

bool SnakeNode::IsHead()
{
	return m_IsHead;
}

Vector2 SnakeNode::GetDirection()
{
	return m_Direction;
}

void SnakeNode::SetDirection(const Vector2& direction)
{
	m_Direction = direction;
}

Vector2 SnakeNode::GetVelocity()
{
	return m_Velocity;
}

void SnakeNode::SetVelocity(const Vector2& velocity)
{
	m_Velocity = velocity;
}

Vector2 SnakeNode::GetPrevPosition()
{
	return m_PrevPosition;
}

void SnakeNode::SetPrevPosition(const Vector2& position)
{
	m_PrevPosition = position;
}

void SnakeNode::Move(int rowId, int coldId)
{
	m_RowId = rowId;
	m_ColId = coldId;
}

void SnakeNode::GetCell(int& rowId, int& colId)
{
	rowId = m_RowId;
	colId = m_ColId;
}
