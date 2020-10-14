#pragma once

#include "IView.h"
#include <cstdint>

struct SDL_Window;

namespace Core
{
	class ApplicationBase;

	struct SDLViewData
	{
		const char* title;
		int16_t width;
		int16_t height;
	};

	class SDLView : public IView
	{
	public:
		SDLView(const char* title, int16_t width, int16_t height);
		virtual ~SDLView();

		virtual void Init() override;

		virtual void ReInitialize() override;

		virtual void Update(ApplicationBase& appBase) override;

		virtual void Terminate() override;

		virtual void GetViewportSize() const override;

		virtual Vector2 GetViewSize() const override;

		virtual void* GetWindow() const override;

		virtual void SetViewSize(int width, int height) override;

		virtual bool ShouldClose() const override;

		virtual const char* GetTitle() const override;

		virtual void SetTitle(const char* title) override;

	private:

		SDLViewData m_Data;
		SDL_Window* m_Window;
		bool m_ShouldQuit;
	};
};