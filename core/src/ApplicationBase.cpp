#include "ApplicationBase.h"

const uint8_t* Core::ApplicationBase::GetKeyboardState(int* numkeys)
{
	return m_Input->GetKeyboardState(numkeys);
}

Vector2 Core::ApplicationBase::GetMousePosition()
{
	return m_Input->GetMousePosition();
}

Vector2 Core::ApplicationBase::GetViewportSize()
{
	return m_Renderer->GetViewportSize();
}

Vector2 Core::ApplicationBase::GetViewSize()
{
	return m_View->GetViewSize();
}

Core::IPainter& Core::ApplicationBase::GetPainter()
{
	return *m_Painter.get();
}

Core::Gui::WidgetManager & Core::ApplicationBase::GetWidgetManager()
{
	return *m_WidgetManager.get();
}
