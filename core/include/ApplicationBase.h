#pragma once

#include "NonCopyable.h"
#include "IView.h"
#include "IRenderer.h"
#include "IPainter.h"
#include "IInput.h"
#include "gui/WidgetManager.h"
#include <memory>

namespace Core
{
	class ApplicationBase : public NonCopyable
	{
		public:

			const uint8_t* GetKeyboardState(int* numkeys);
			Vector2 GetMousePosition();
			Vector2 GetViewportSize();
			Vector2 GetViewSize();
			IPainter& GetPainter();
			Core::Gui::WidgetManager& GetWidgetManager();

		protected:

			std::unique_ptr<IInput> m_Input;
			std::unique_ptr<IPainter> m_Painter;
			std::unique_ptr<IRenderer> m_Renderer;
			std::unique_ptr<IView> m_View;
			std::unique_ptr<Core::Gui::WidgetManager> m_WidgetManager;

		private:

	};
};