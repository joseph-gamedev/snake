#pragma  once

#include "GameObject.h"
#include "SnakeNode.h"

#include <vector>

class Snake :public GameObject
{
public:

	Snake(const Vector2& position, const Vector2& size, Board<int>& board, const Vector2& playAreaStart);
	virtual ~Snake();

	virtual void Init() {}
	virtual void Draw(Core::IPainter* painter) override;
	virtual void Update(float deltaTime);
	virtual void Shutdown() {}

	Vector2 GetDirection();
	void SetDirection(const Vector2& direction);
	void Stop();
	void Grow();

private:

	Vector2 m_Direction;
	Board<int> m_Board;
	std::vector<SnakeNode> m_Nodes;
	Vector2 m_PlayAreaStart;
	float m_MoveTime;
	float m_ElapsedTime;
};

