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

}

void GameScene::Shutdown()
{
}

void GameScene::Update(float timeDelta)
{
	testposition += Vector2::One * 10.5f * timeDelta;
}

void GameScene::Draw()
{
	Vector2 viewportSize = m_application->GetViewportSize();
	m_Painter.SetColor(255, 0, 0, 255);
	m_Painter.DrawLine(Vector2::One, Vector2::One * 100);
	m_Painter.SetColor(0, 23, 255, 255);
	m_Painter.DrawThickLine(Vector2::One *200, Vector2::One * 300,30);
	m_Painter.DrawCircle(testposition, 100);
	m_Painter.DrawFillCircle(viewportSize/2, 100);
	DrawTable(4, 4, Vector2(100,100), Vector2::One * 100);
}

void GameScene::DrawTable(int8_t rows, int8_t cols, const Vector2& startPos, const Vector2& cellSize)
{
	Vector2 tableEnd = startPos + cellSize;
	m_Painter.SetColor(0, 0, 0, 255);
	for (size_t rowId = 0; rowId <= rows; rowId++)
	{
		Vector2 lineStart = startPos + Vector2(rowId * cellSize.X, 0);
		Vector2 lineEnd = startPos + Vector2(rowId * cellSize.X, cellSize.Y * cols);
		m_Painter.DrawThickLine(lineStart, lineEnd, 5);
	}
	for (size_t colId = 0; colId <= cols; colId++)
	{
		Vector2 lineStart = startPos + Vector2(0, colId * cellSize.Y);
		Vector2 lineEnd = startPos + Vector2(cellSize.X * rows, colId * cellSize.Y);
		m_Painter.DrawThickLine(lineStart, lineEnd, 5);
	}
}
