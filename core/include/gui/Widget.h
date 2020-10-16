#pragma once

#include "WidgetContainer.h"

namespace Core
{
	class IPainter;

	namespace Gui
	{
		class Widget : public WidgetContainer
		{
			public:
				Widget(Vector2& position, Vector2& size)
					: m_Position(position)
				{
					m_widgetBounds = Recti{(int)position.X, (int)position.Y, (int)size.X, (int)size.Y};
				}

				virtual ~Widget(){}

				virtual void Draw(IPainter* painter) {}
				virtual void SetVisiblility(bool visibility) {}
				virtual void Update(float deltaTime) {}

				virtual void OnMouseEnter(Vector2& position) {}
				virtual void OnMouseLeave(Vector2& position) {}
				virtual void OnMouseMove(Vector2& position) {}
				//virtual void OnMouseDown(Vector2& position, int clickCount) {}
				virtual void OnMouseDown(Vector2& position, int btnId, int clickCount) {}
				//virtual void OnMouseUp(Vector2& position) {}
				//virtual void OnMouseUp(Vector2& position, int clickCount) {}
				virtual void OnMouseUp(Vector2& position, int btnId, int clickCount) {}
				virtual void OnMouseDrag(Vector2& position) {}
				virtual void OnMouseWheel(int wheelDelta) {}

				void SetEnabled(bool isEnabled) { m_IsEnabled = isEnabled; }
				bool IsEnabled() { return m_IsEnabled; }

			protected:

				Vector2 m_Position;

			private:

				bool m_IsEnabled = false;
				
		};
	};
};