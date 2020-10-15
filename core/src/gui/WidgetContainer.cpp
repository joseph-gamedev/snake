#include "gui/WidgetContainer.h"
#include "gui/Widget.h"

void Core::Gui::WidgetContainer::Draw(IIPainter * painter)
{
	for (auto widget : m_Widgets)
	{
		widget->Draw(painter);
	}
}

void Core::Gui::WidgetContainer::Update(float deltaTime)
{
	for (auto widget : m_Widgets)
	{
		widget->Update(deltaTime);
	}
}

void Core::Gui::WidgetContainer::AddWidget(Widget * widget)
{
	if (!ContainsWidget(widget))
	{
		/*auto iterator = m_Widgets.begin();
		while (iterator != m_Widgets.end())
		{
			Widget *itrWidget = *iterator;
			if (itrWidget->GetZOrder() > widget->GetZOrder())
			{
				m_Widgets.insert(iterator, widget);
				return;
			}

			++iterator;
		}*/
		m_Widgets.push_back(widget);
	}
}

void Core::Gui::WidgetContainer::RemoveWidget(Widget * widget)
{
	auto iterator = std::find(m_Widgets.begin(), m_Widgets.end(), widget);
	if (iterator != m_Widgets.end())
	{
		m_Widgets.erase(iterator);
	}
}

bool Core::Gui::WidgetContainer::ContainsWidget(Widget * widget)
{
	return std::find(m_Widgets.begin(), m_Widgets.end(), widget) != m_Widgets.end();
}

int Core::Gui::WidgetContainer::GetZOrder()
{
	return m_zOrder;
}
