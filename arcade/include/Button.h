#pragma once

#include <ArcadeCore.h>
#include <functional>

using ButtonEvent = std::function<void()>;

struct ButtonData
{
	Core::Color m_NormalColor = Core::Color::BLUE;
	Core::Color m_HoverColor = Core::Color::GREEN;
	Core::Color m_PressedColor = Core::Color::RED;
	Core::Color m_DisabledColor = Core::Color::BLACK;
	Core::Color m_OutlineColor ;
};

class Button : public Core::Gui::Widget
{
	public:

		Button(Vector2& position, Vector2& size);
		virtual ~Button() {}

		virtual void Draw(Core::IPainter* painter) override;
		virtual void SetVisiblility(bool visibility) {}
		virtual void Update(float deltaTime) override;

		virtual void OnMouseEnter(Vector2& position) override;
		virtual void OnMouseLeave(Vector2& position) override;
		virtual void OnMouseMove(Vector2& position) override;
		virtual void OnMouseDown(Vector2& position, int btnId, int clickCount) override;
		virtual void OnMouseUp(Vector2& position, int btnId, int clickCount) override;

		void RegisterBtnEvent(const ButtonEvent& btnEvent);

	private:

		Core::Color m_PaintColor;
		Core::Color m_OutlineColor;
		ButtonData m_ButtonData;
		ButtonEvent m_PressedEvent;
};