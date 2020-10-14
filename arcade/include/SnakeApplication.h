#pragma once

#include <ArcadeCore.h>
#include <memory>

class GameScene;

const char* APP_TITLE = "Snake";
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const Color CLEAR_COLOR = Color{ 255,255,255,255 };

class SnakeApplication : public Core::Application
{
	public:
		SnakeApplication(const Core::AppData& data);

		virtual void Load() override;

		virtual void OnLoadComplete() override;

		virtual void Start() override;

		virtual void Stop() override;

		virtual void PostUpdate(float deltaTime) override;

		virtual void Update(float timeDelta) override;

		virtual void Draw() override;

	private:

		std::unique_ptr<GameScene> m_scene;
};

std::unique_ptr<Core::Application> CreateApplication()
{
	return std::make_unique<SnakeApplication>(Core::AppData{ APP_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, CLEAR_COLOR });
}

