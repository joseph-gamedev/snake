#include "GameScene.h"
#include <ArcadeCore.h>
#include <SDL_ttf.h>
#include <filesystem>
#include "Button.h"

const char* fontPathTimes = "fonts/times.ttf";

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
	std::string fontPath  = SDL_GetBasePath();
	fontPath.append(fontPathTimes);

	font = TTF_OpenFont(fontPath.c_str(), 40);
	if (!font) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		// handle error
	}
	m_PlayBtn = std::make_unique<Button>(Vector2(100,5), Vector2(200,40));
	auto& widgetManager = m_application->GetWidgetManager();
	widgetManager.AddWidget(m_PlayBtn.get());
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
	/*Vector2 viewportSize = m_application->GetViewportSize();
	m_Painter.SetColor(255, 0, 0, 255);
	m_Painter.DrawLine(Vector2::One, Vector2::One * 100);
	m_Painter.SetColor(0, 23, 255, 255);
	m_Painter.DrawThickLine(Vector2::One *200, Vector2::One * 300,30);
	m_Painter.DrawCircle(testposition, 100);
	m_Painter.DrawFillCircle(viewportSize/2, 100);
	DrawTable(4, 4, Vector2(100,100), Vector2::One * 100);*/
	//DrawTable(20, 35, Vector2(50, 100), Vector2::One * 20);
	m_Painter.DrawString(font, "Hello World", Core::Recti{0,0,300,100}, Core::Color::RED);
}

void GameScene::DrawTable(int8_t rows, int8_t cols, const Vector2& startPos, const Vector2& cellSize)
{
	float lineSize = 1.0f;
	Vector2 tableEnd = startPos + cellSize;
	m_Painter.SetColor(0, 155, 155, 150);
	for (size_t colId = 1; colId < cols; colId++)
	{
		Vector2 lineStart = startPos + Vector2(colId * cellSize.Y, 0);
		Vector2 lineEnd = startPos + Vector2(colId * cellSize.Y, cellSize.Y * rows-1);
		m_Painter.DrawLine(lineStart, lineEnd);
	}
	for (size_t rowId = 1; rowId < rows; rowId++)
	{
		Vector2 lineStart = startPos + Vector2(0, rowId * cellSize.X);
		Vector2 lineEnd = startPos + Vector2(cellSize.X * cols-1, rowId * cellSize.X);
		m_Painter.DrawLine(lineStart, lineEnd);
	}
	m_Painter.SetColor(Core::Color::BLACK);
	m_Painter.DrawRectangle(startPos.X, startPos.Y, cellSize.X * cols, cellSize.Y * rows);
}
