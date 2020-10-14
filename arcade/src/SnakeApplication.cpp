#include "SnakeApplication.h"
#include "GameScene.h"

SnakeApplication::SnakeApplication(const Core::AppData & data)
	: Application(data)
{
	m_scene = std::make_unique<GameScene>(this);
}

void SnakeApplication::Load()
{
}

void SnakeApplication::OnLoadComplete()
{
}

void SnakeApplication::Start()
{
	m_scene->Init();
}

void SnakeApplication::Stop()
{
	m_scene->Shutdown();
}

void SnakeApplication::PostUpdate(float deltaTime)
{
	
}

void SnakeApplication::Update(float timeDelta)
{
	m_scene->Update();
}

void SnakeApplication::Draw()
{
	m_scene->Draw();
}
