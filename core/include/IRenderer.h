#pragma once
namespace Core
{
	class IRenderer
	{
	public:
		virtual ~IRenderer() {}

		virtual void Init() = 0;

		//rbgba values from 0 to 1
		virtual void ClearColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) = 0;

		virtual void ReInitialize() = 0;

		virtual void SwapBuffers() = 0;

		virtual void Terminate() = 0;

		virtual Vector2 GetViewportSize() const = 0;

		virtual void* Get() = 0;
	};
};