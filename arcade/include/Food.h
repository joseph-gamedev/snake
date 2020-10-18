#pragma  once

#include "GameObject.h"

class Food :public GameObject
{
public:

	Food();
	Food(const Vector2& position, const Vector2& size);
	virtual ~Food();

	virtual void Init() {}
	virtual void Draw(Core::IPainter* painter) override;
	virtual void Update(float deltaTime) {}
	virtual void Shutdown() {}

private:
};

