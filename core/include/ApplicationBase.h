#pragma once

#include "NonCopyable.h"
#include "IView.h"
#include "IRenderer.h"
#include "IPainter.h"
#include "IInput.h"
#include <memory>

namespace Core
{
	class ApplicationBase : public NonCopyable
	{
		public:
			Vector2 GetMousePosition();
			Vector2 GetViewportSize();
			Vector2 GetViewSize();
			IPainter& GetPainter();

		protected:
			std::unique_ptr<IInput> m_Input;
			std::unique_ptr<IPainter> m_Painter;
			std::unique_ptr<IRenderer> m_Renderer;
			std::unique_ptr<IView> m_View;
		private:

	};
};