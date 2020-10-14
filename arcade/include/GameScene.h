#pragma once 

#include <NonCopyable.h>
#include <memory>

template<typename T>
class Board;

namespace Core
{
	class Application;
	class IPainter;
}
class GameScene : public Core::NonCopyable
{
	public:

		GameScene(Core::Application* const application);
		~GameScene();

		void Init();

		void Shutdown();

		void Update();

		void Draw();

	private:

		Core::Application* const m_application;
		std::unique_ptr<Board<int>> m_board;
		Core::IPainter& m_Painter;

};