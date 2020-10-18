#include "Snake.h"
#include <ArcadeCore.h>

Snake::Snake(const Vector2& position, const Vector2& size, Board<int>& board, const Vector2& playAreaStart)
	: GameObject(position, size)
	, m_Board(board)
	, m_PlayAreaStart(playAreaStart)
{
	m_Nodes.push_back(SnakeNode(position, size));
	Vector2 cellPosition = (position - playAreaStart);
	int cellRowId = cellPosition.X / size.X;
	int cellColId = cellPosition.Y / size.Y;

	auto& front = m_Nodes.front();
	front.Move(cellRowId, cellColId);
	front.SetAsHead(true);
	Grow();
	Grow();
	Grow();
}

Snake::~Snake()
{

}

void Snake::Draw(Core::IPainter* painter)
{
	for (auto& node: m_Nodes)
	{
		node.Draw(painter);
	}
}

void Snake::Update(float deltaTime)
{
	if (m_Nodes.size() <= 0)
		return;

	auto& headNode = m_Nodes.front();
	int headRowId = m_Direction.X, headColId = m_Direction.Y;
	headNode.GetCell(headRowId, headColId);
	headRowId += m_Direction.X;
	headColId += m_Direction.Y;

	if (headRowId < 0 || headColId < 0 || headRowId > m_Board.GetTotalRows() || headColId > m_Board.GetTotalCols())
		return;
	auto& tailNode = m_Nodes.back();
	tailNode.Move(headRowId, headColId);
	Vector2 newPosition = m_PlayAreaStart + Vector2(headRowId * m_Size.X, headColId * m_Size.Y);
	tailNode.SetPosition(newPosition);
	m_Nodes.insert(m_Nodes.begin(), tailNode);
	m_Nodes.pop_back();
	//m_Nodes[m_Nodes.size() - 1];
	//m_Nodes[0].Move(headRowId, headColId);

	
	return;
	//Vector2 nextPosition = m_Nodes[0].GetPosition();
	//Vector2 oldVelocity  = m_Nodes[0].GetVelocity();
	//m_Nodes[1].SetPosition(m_Nodes[0].GetPosition());
	m_Nodes[0].SetPrevPosition(m_Nodes[0].GetPosition());
	m_Nodes[0].SetPosition(m_Nodes[0].GetPosition() + m_Direction * deltaTime * m_Size.Y);
	//m_Nodes[0].SetVelocity(m_Direction * deltaTime * m_Size.Y);
	//Vector2 nextPosition;
	//for (size_t index = m_Nodes.size()-1; index < 0; index--)
	//{
	//	//nextPosition = m_Nodes[index - 1].GetPosition();
	//	m_Nodes[index].SetPosition(m_Nodes[index - 1].GetPosition());
	//}
	for (size_t index = 1; index < m_Nodes.size(); index++)
	{
		//RopeSection currentRopeSection = _ropeSections[i];
		Vector2 velocity = m_Nodes[index-1].GetPosition() - m_Nodes[index-1].GetPrevPosition();
		//updating the old position
		m_Nodes[index].SetPrevPosition(m_Nodes[index].GetPosition());
		//we add the velocity at the current position
		//if(index != 0)
		m_Nodes[index].SetPosition(m_Nodes[index].GetPosition() += velocity);
		//adding the gravity
		//currentRopeSection.pos += gravity * Time.deltaTime;

		//nextPosition = m_Nodes[index - 1].GetPosition();
		//m_Nodes[index].SetPosition(m_Nodes[index].GetPosition() + oldVelocity);
		//m_Nodes[index].SetVelocity(oldVelocity);
		//nextPosition = m_Nodes[index - 1].GetPosition();
		//oldVelocity = 
	}
	

	//m_Nodes.pop_back();
	//m_Nodes.push_front()
	//Vector2 direction = m_Direction * m_Size.Y ;
	//Vector2 position = Vector2::Zero;
	//Vector2 prevVelocity;
	//if (m_Nodes.size() > 0)
	//{
	//	auto& headNode = m_Nodes.front();
	//	position = headNode.GetPosition();
	//}
	//Vector2 nextPosition = position;
	//Vector2 velocity = direction * deltaTime;
	//
	//for (auto& node : m_Nodes)
	//{	
	//	
	//	if (node.IsHead())
	//	{
	//		prevVelocity = node.GetVelocity();
	//		nextPosition = node.GetPosition();
	//		node.SetPosition(node.GetPosition() + velocity);
	//		node.SetVelocity(velocity);
	//	}
	//	else
	//	{
	//		node.SetPosition(node.GetPosition() + prevVelocity);
	//	}
	//	//node.SetDirection(direction);
	//	node.Update(deltaTime);
	//	//if (!node.IsHead())
	//	{
	//		//nextPosition = node.GetPosition();
	//	}
	//	//direction = node.GetDirection();
	//}
}

Vector2 Snake::GetDirection()
{
	return m_Direction;
}

void Snake::SetDirection(const Vector2& direction)
{
	m_Direction = direction;
}

void Snake::Stop()
{
	for (auto& node : m_Nodes)
	{
		node.SetDirection(Vector2::Zero);
	}
}

void Snake::Grow()
{
	auto& node = m_Nodes.back();
	Vector2 direction = node.GetDirection();
	Vector2 size = m_Size;
	Vector2 position = node.GetPosition() - direction;
	
	m_Nodes.push_back(SnakeNode(position, size));
}

