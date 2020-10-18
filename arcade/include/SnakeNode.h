#pragma  once

#include "GameObject.h"

class SnakeNode :public GameObject
{
	public:

		SnakeNode(const Vector2& position, const Vector2& size);
		virtual ~SnakeNode();

		virtual void Init() {}
		virtual void Draw(Core::IPainter* painter) override;
		virtual void Update(float deltaTime);
		virtual void Shutdown() {}

		void SetAsHead(bool isHead);
		bool IsHead();

		Vector2 GetDirection();
		void SetDirection(const Vector2& direction);

		Vector2 GetVelocity();
		void SetVelocity(const Vector2& velocity);

		Vector2 GetPrevPosition();
		void SetPrevPosition(const Vector2& position);

		void Move(int rowId, int coldId);
		void GetCell(int& rowId, int& colId);

	private:

		bool m_IsHead;
		Vector2 m_Direction;
		Vector2 m_Velocity;
		Vector2 m_PrevPosition;
		int m_RowId;
		int m_ColId;
};

