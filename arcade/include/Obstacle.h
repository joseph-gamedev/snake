#pragma  once

#include "GameObject.h"

class Obstacle :public GameObject
{
public:

	Obstacle(const Vector2& position, const Vector2& size);
	virtual ~Obstacle();

	virtual void Init() {}
	virtual void Draw(Core::IPainter* painter) override;
	virtual void Update(float deltaTime) {}
	virtual void Shutdown() {}

private:


};

