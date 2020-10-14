#pragma once

namespace Core
{
	class IRenderer;
	class ApplicationBase;
	class IView
	{
	public:
		virtual ~IView() {};

		virtual void GetViewportSize() const = 0;

		virtual Vector2 GetViewSize() const = 0;

		virtual void* GetWindow() const = 0;

		virtual const char* GetTitle() const = 0;

		virtual void Init() = 0;

		virtual void ReInitialize() = 0;

		virtual bool ShouldClose() const = 0;

		virtual void SetViewSize(int width, int height) = 0;

		virtual void SetTitle(const char* title) = 0;

		virtual void Terminate() = 0;

		virtual void Update(ApplicationBase& appBase) = 0;
	};
};