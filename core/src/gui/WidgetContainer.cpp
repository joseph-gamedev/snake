#include "gui/WidgetContainer.h"
#include "gui/Widget.h"

void Core::Gui::WidgetContainer::Draw(IPainter * painter)
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

void Core::Gui::WidgetContainer::SetActive(Widget * widget, bool active)
{
	if (widget)
	{
		widget->SetEnabled(active);
	}
}

void Core::Gui::WidgetContainer::RemoveAllWidgets(bool recursive)
{
}

int Core::Gui::WidgetContainer::GetZOrder()
{
	return m_zOrder;
}

Core::Recti & Core::Gui::WidgetContainer::GetBounds()
{
	return m_widgetBounds;
}

Core::Gui::Widget * Core::Gui::WidgetContainer::GetWidgetAt(int x, int y)
{
	for (auto widget : m_Widgets)
	{
		if(widget->GetBounds().Contains(Vector2(x,y)))
			return widget;
	}

	return nullptr;
}
