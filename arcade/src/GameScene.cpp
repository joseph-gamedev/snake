#include "GameScene.h"
#include <ArcadeCore.h>

GameScene::GameScene(Core::Application * const application)
	: m_application(application)
	, m_Painter(application->GetPainter())
{
	m_board = std::make_unique<Board<int>>(BoardInfo{10,10,Vector2::Zero,Vector2::One*10 ,Vector2::Zero, Vector2::Zero },0);
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{
	m_board->Set(3, 4, 5);
	m_application->GetViewSize();
}

void GameScene::Shutdown()
{
}

void GameScene::Update()
{
}

void GameScene::Draw()
{
	//m_Painter.SetDrawScale(Vector2::One);
	m_Painter.SetColor(255, 0, 0, 255);
	m_Painter.DrawLine(Vector2::One, Vector2::One * 100,1);
	//m_Painter.SetDrawScale(Vector2::One * 2.0f);
	m_Painter.SetColor(0, 0, 0, 255);
	m_Painter.DrawLine(Vector2::One *200, Vector2::One * 300,30);
}
