#include "Application.h"
#include "SDLView.h"
#include "SDLRenderer.h"
#include "SDLPainter.h"
#include <SDL.h>

Core::Application::Application(const AppData & data)
	: m_appData(data)
	, m_lastTick(0)
{
	m_View = std::make_unique<SDLView>(data.title, data.width, data.height);
	m_View->Init();

	m_Renderer = std::make_unique<SDLRenderer>(*(dynamic_cast<SDLView*>(m_View.get())));
	m_Renderer->Init();

	m_Painter = std::make_unique<SDLPainter>(static_cast<SDL_Renderer*>(m_Renderer->Get()));
}

Core::Application::~Application()
{
	m_Renderer->Terminate();
	m_View->Terminate();
}

void Core::Application::Run()
{
	

	Start();
	while (!m_View->ShouldClose())
	{
		uint32_t now = SDL_GetTicks();
		float deltaTime = (now - m_lastTick) / 1000.0f;

		m_View->Update(*this);
		m_Renderer->ClearColor(m_appData.color.red, m_appData.color.green, m_appData.color.blue, m_appData.color.alpha);
		Update(deltaTime);
		PostUpdate(deltaTime);
		Draw();
		m_Renderer->SwapBuffers();

		m_lastTick = now;
	}
	Stop();
}
