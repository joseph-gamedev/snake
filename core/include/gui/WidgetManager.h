#pragma once 

#include "WidgetContainer.h"

namespace Core
{
	class IIPainter;

	namespace Gui
	{
		class Widget;

		class WidgetManager : public WidgetContainer
		{
			public:
				WidgetManager();
				virtual ~WidgetManager() {}

				void MousePosition(int x, int y);
				void MouseUp(int x, int y, int btnId, int clickCount);
				void MouseDown(int x, int y, int btnId, int clickCount);
				bool MouseMove(int x, int y);
				bool MouseDrag(int x, int y);
				bool MouseExit(int x, int y);
				void MouseWheel(int wheelDelta);

			private:

				Widget* m_FocusedWidget;
				Widget* m_OverWidget;
				Widget* m_LastOverWidget;
				Widget* m_LastDownWidget;

		};
	};
};