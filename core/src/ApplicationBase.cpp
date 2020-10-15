#include "ApplicationBase.h"

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
