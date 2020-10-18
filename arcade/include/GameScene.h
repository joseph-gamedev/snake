#pragma once 

#include <NonCopyable.h>
#include <memory>
#include "GameObject.h"
#include "Timer.h"

template<typename T>
class Board;

class Button;
struct _TTF_Font;

namespace Core
{
	class Application;
	class IPainter;
}

const int PLAY_AREA_WIDTH = 700;
const int PLAY_AREA_HEIGHT = 500;

class GameScene : public Core::NonCopyable 
{
	public:

		GameScene(Core::Application* const application);
		~GameScene();

		void Init();

		void Shutdown();

		void Update(float timeDelta);

		void Draw();

	private:

		void PlayGame();
		void DrawTable(int8_t rows, int8_t cols, const Vector2& startPos, const Vector2& cellSize);
		void DrawPlayArea(int x, int y , int width, int height);
		void PlaceFood();
		Vector2 GetRandomCellPos();

	private:

		Core::Application* const m_application;

		std::unique_ptr<Board<int>> m_board;

		Core::IPainter& m_Painter;

		std::unique_ptr<Button> m_PlayBtn;

		_TTF_Font* font;

		std::unique_ptr<GameObject> m_Food;
		std::vector<std::unique_ptr<GameObject>> m_Obstacles;
		std::unique_ptr<GameObject> m_Snake;
		
		Vector2 m_PlayAreaStart;
		Vector2 m_CellSize;

		int m_NumRows;
		int m_NumCols;
		std::unique_ptr<Core::Timer>m_foodTimer;
};