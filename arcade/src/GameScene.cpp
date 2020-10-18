#include "GameScene.h"
#include <ArcadeCore.h>
#include <SDL_ttf.h>
#include <string>
#include "Button.h"
#include "Food.h"
#include "Snake.h"

const char* fontPathTimes = "fonts/times.ttf";

GameScene::GameScene(Core::Application * const application)
	: m_application(application)
	, m_Painter(application->GetPainter())
	, m_NumRows(25)
	, m_NumCols(35)
	, m_PlayAreaStart(Vector2(50, 50))
	, m_CellSize(Vector2(20,20))
{
	m_board = std::make_unique<Board<int>>(BoardInfo{ m_NumRows,m_NumCols,Vector2::Zero,Vector2::One*10 ,Vector2::Zero, Vector2::Zero },0);
	m_Food = std::make_unique<Food>(Vector2::Zero, m_CellSize);
	m_foodTimer = std::make_unique<Core::Timer>(2, std::bind(&GameScene::PlaceFood, this));
	m_foodTimer->Start();

	m_Snake = std::make_unique<Snake>(GetRandomCellPos(), m_CellSize, *m_board.get(), m_PlayAreaStart);
	auto snake = dynamic_cast<Snake*>(m_Snake.get());
	snake->SetDirection(Vector2::Up * -1);
	PlaceFood();
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
	/*m_PlayBtn = std::make_unique<Button>(Vector2(100,5), Vector2(200,40));
	auto& widgetManager = m_application->GetWidgetManager();
	widgetManager.AddWidget(m_PlayBtn.get());*/
}

void GameScene::Shutdown()
{
}

void GameScene::Update(float timeDelta)
{
	auto snake = dynamic_cast<Snake*>(m_Snake.get());
	Vector2 direction = snake->GetDirection();
	const Uint8* keystates = m_application->GetKeyboardState(nullptr);
	if (keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D])
	{
		direction = Vector2::Right;
	}
	if (keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A])
	{
		direction = Vector2::Right * -1;
	}
	if (keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W])
	{
		direction = Vector2::Up * -1;
	}
	if (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S])
	{
		direction = Vector2::Up ;
	}
	
	snake->SetDirection(direction);
	m_foodTimer->Update(timeDelta);
	m_Snake->Update(timeDelta);
	//PlaceFood();
	int x = 0;
}

void GameScene::Draw()
{
	m_Painter.ClearColor(Core::Color::BLACK);
	//DrawTable(m_NumRows, m_NumCols, m_PlayAreaStart, m_CellSize);
	DrawPlayArea(m_PlayAreaStart.X, m_PlayAreaStart.Y, m_CellSize.X * m_NumCols, m_CellSize.Y * m_NumRows);
	m_Food->Draw(&m_Painter);
	m_Snake->Draw(&m_Painter);
	/*Vector2 viewportSize = m_application->GetViewportSize();
	m_Painter.SetColor(255, 0, 0, 255);
	m_Painter.DrawLine(Vector2::One, Vector2::One * 100);
	m_Painter.SetColor(0, 23, 255, 255);
	m_Painter.DrawThickLine(Vector2::One *200, Vector2::One * 300,30);
	m_Painter.DrawCircle(testposition, 100);
	m_Painter.DrawFillCircle(viewportSize/2, 100);
	DrawTable(4, 4, Vector2(100,100), Vector2::One * 100);*/
	//DrawTable(20, 35, Vector2(50, 100), Vector2::One * 20);
	//m_Painter.DrawString(font, "Hello World", Core::Recti{0,0,300,100}, Core::Color::RED);
}

void GameScene::PlayGame()
{
	m_foodTimer->Reset();
	m_foodTimer->Start();
}

void GameScene::DrawTable(int8_t rows, int8_t cols, const Vector2& startPos, const Vector2& cellSize)
{
	float lineSize = 1.0f;
	Vector2 tableEnd = startPos + cellSize;
	m_Painter.SetColor(100, 100, 1, 1);
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
	//m_Painter.SetColor(Core::Color::WHITE);
	//m_Painter.DrawRectangle(startPos.X, startPos.Y, cellSize.X * cols, cellSize.Y * rows);
}

void GameScene::DrawPlayArea(int x, int y, int width, int height)
{
	int offset = 2;
	m_Painter.SetColor(Core::Color::WHITE);
	m_Painter.DrawRectangle(x, y, width, height);
	//m_Painter.DrawRectangle(x-offset, y-offset, width+offset*2, height+offset*2);
}

void GameScene::PlaceFood()
{
	int foodPosRowId, foodPosColId;
	m_board->GetRandomFreeCell(foodPosRowId, foodPosColId);
	Vector2 foodPos = m_PlayAreaStart + Vector2(foodPosColId * m_CellSize.X, foodPosRowId * m_CellSize.Y);
	m_Food->SetPosition(foodPos);
}

Vector2 GameScene::GetRandomCellPos()
{
	int posRowId, posColId;
	m_board->GetRandomFreeCell(posRowId, posColId);
	Vector2 pos = m_PlayAreaStart + Vector2(posColId * m_CellSize.X, posRowId * m_CellSize.Y);
	return pos;
}
