#pragma once

namespace Core
{
	class IPainter;
}

class GameObject
{
	public:

		GameObject(const Vector2& position, const Vector2& size);
		GameObject();

		virtual ~GameObject() {}

		Vector2 GetPosition();
		void SetPosition(const Vector2& position);

		Vector2 GetSize();

		virtual void Init() {}
		virtual void Draw(Core::IPainter* painter){}
		virtual void Update(float deltaTime){}
		virtual void Shutdown(){}

	protected:
		
		Vector2 m_Position;
		Vector2 m_Size;
};