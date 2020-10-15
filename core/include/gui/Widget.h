#pragma once

#include "WidgetContainer.h"

namespace Core
{
	class IIPainter;

	namespace Gui
	{
		class Widget : public WidgetContainer
		{
			public:

				virtual ~Widget(){}

				virtual void Draw(IIPainter* painter);
				virtual void SetVisiblility(bool visibility);
				virtual void Update(float deltaTime);

				virtual void OnMouseEnter();
				virtual void OnMouseLeave();
				virtual void OnMouseMove(Vector2& position);
				virtual void OnMouseDown(Vector2& position, int clickCount);
				virtual void OnMouseDown(Vector2& position, int btnId, int clickCount);
				virtual void OnMouseUp(Vector2& position);
				virtual void OnMouseUp(Vector2& position, int clickCount);
				virtual void OnMouseUp(Vector2& position, int btnId, int clickCount);
				virtual void OnMouseDrag(Vector2& position);
				virtual void OnMouseWheel(int wheelDelta);

				

		};
	};
};