#include "SDLView.h"
#include <SDL.h>

Core::SDLView::SDLView(const char* title, int16_t width, int16_t height)
	: m_Data{ title, width, height }
	, m_ShouldQuit(false)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
	}
}

Core::SDLView::~SDLView()
{
}

void Core::SDLView::Init()
{
	m_Window = SDL_CreateWindow(
		m_Data.title,					   // window title
		SDL_WINDOWPOS_UNDEFINED,           // initial x position
		SDL_WINDOWPOS_UNDEFINED,           // initial y position
		m_Data.width,                      // width, in pixels
		m_Data.height,                     // height, in pixels
		0								   // flags 
	);

	if (!m_Window)
	{
		SDL_Log("Unable to create SDL window: %s", SDL_GetError());
	}
}

void Core::SDLView::ReInitialize()
{
}

void Core::SDLView::Update(ApplicationBase & appBase)
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		/* handle your event here */
		switch (event.type)
		{
		case SDL_QUIT:
			m_ShouldQuit = true;
			break;
		default:
			break;
		}
	}
}

void Core::SDLView::Terminate()
{
	if (m_Window)
	{
		// Close and destroy the window
		SDL_DestroyWindow(m_Window);
	}
	// Clean up
	SDL_Quit();
}

Vector2 Core::SDLView::GetViewSize() const
{
	return Vector2::One;
}

void * Core::SDLView::GetWindow() const
{
	return m_Window;
}

void Core::SDLView::SetViewSize(int width, int height)
{
	m_Data.width = width;
	m_Data.height = height;
}

bool Core::SDLView::ShouldClose() const
{
	return m_ShouldQuit;
}

const char* Core::SDLView::GetTitle() const
{
	return m_Data.title;// TODO: insert return statement here
}

void Core::SDLView::SetTitle(const char* title)
{
	m_Data.title = title;
}
