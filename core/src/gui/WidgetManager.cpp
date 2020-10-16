#include "gui/WidgetManager.h"
#include "gui/Widget.h"

Core::Gui::WidgetManager::WidgetManager()
	: m_FocusedWidget(nullptr)
	, m_OverWidget(nullptr)
	, m_LastOverWidget(nullptr)
{

}

void Core::Gui::WidgetManager::MousePosition(int x, int y)
{
	Widget* widget = GetWidgetAt(x, y);
	Vector2 mousePos = Vector2(x, y);
	if (widget)
	{		
		if (widget != m_OverWidget)
		{
			//m_LastOverWidget = m_OverWidget;
			if (m_LastOverWidget)
			{
				m_LastOverWidget->OnMouseLeave(mousePos);
			}

			widget->OnMouseEnter(mousePos);
			widget->OnMouseMove(mousePos);
			m_OverWidget = widget;
		}
		else
		{
			widget->OnMouseMove(mousePos);
		}
	}
	else
	{
		if (m_LastOverWidget)
		{
			m_LastOverWidget->OnMouseLeave(mousePos);
			m_LastOverWidget = nullptr;
		}
		m_OverWidget = nullptr;
		
	}
	m_LastOverWidget = m_OverWidget;
}

void Core::Gui::WidgetManager::MouseUp(int x, int y, int btnId, int clickCount)
{
	Widget* widget = GetWidgetAt(x, y);
	if (widget)
	{
		widget->OnMouseUp(Vector2(x, y), btnId, clickCount);
	}
}

void Core::Gui::WidgetManager::MouseDown(int x, int y, int btnId, int clickCount)
{
	Widget* widget = GetWidgetAt(x, y);
	if (widget)
	{
		if (widget != m_LastDownWidget)
		{
			m_LastDownWidget = widget;
		} 
		widget->OnMouseDown(Vector2(x, y) , btnId, clickCount);
	}
}

bool Core::Gui::WidgetManager::MouseMove(int x, int y)
{
	MousePosition(x, y);
	return false;
}

bool Core::Gui::WidgetManager::MouseDrag(int x, int y)
{
	return false;
}

bool Core::Gui::WidgetManager::MouseExit(int x, int y)
{
	return false;
}

void Core::Gui::WidgetManager::MouseWheel(int wheelDelta)
{
	if (m_FocusedWidget)
	{
		m_FocusedWidget->OnMouseWheel(wheelDelta);
	}
}
