#pragma once
namespace Core
{
	class IIPainter;

	namespace Gui
	{
		class Widget;

		class WidgetContainer
		{
			public:

				virtual ~WidgetContainer() {}

				virtual void Draw(IIPainter* painter);
				virtual void Update(float deltaTime);

				virtual void AddWidget(Widget* widget);
				virtual void RemoveWidget(Widget* widget);
				virtual bool ContainsWidget(Widget* widget);
				virtual void SetActive(Widget* widget, bool active);
				virtual void RemoveAllWidgets(bool recursive = false);

				int GetZOrder();

			private:

				std::vector<Widget*> m_Widgets;
				WidgetContainer* m_Parent;
				int m_zOrder;
		};
	};
};