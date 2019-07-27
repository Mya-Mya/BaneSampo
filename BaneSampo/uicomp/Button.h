#pragma once
#include"UIComponent.h"
#include<string>
#include"UICompTool.h"
#include"ActionListener.h"
#include"Text.h"
#include"Mouse.h"
#include"Box.h"
#include<list>
class Button :public UIComponent {
protected:
	std::list<ActionListener*>listenerList;
	Text*_text;
	Box*_normal;
	Box*_onMouse;
	Box*_pushing;
	Box*_showing;
	std::list<UIComponent*>myCompList;
	bool _isPushing = false;
public:
	inline Button();
	inline Button(std::string text, int font);
	inline Button(std::string text, int font, int bgNormalColor, int bgOnmouseColor, int bgClickingColor, int frColor);
	inline Button(std::string text, int font, int bgNormalColor, int bgOnmouseColor, int bgClickingColor, int frColor,Vec2 pos,Part part,Vec2 size);
	inline void addActionListener(ActionListener *l);
	inline void setPos(Vec2 pos, Part part)override;
	inline void setSize(Vec2 size, Part part)override;
	void update();
	void draw();
	Text* getText();
	Box* getNormalBox();
	Box* getOnMouseBox();
	Box* getPushingBox();
};
inline Button::Button()
	:Button("uicomp::Button", 0)
{
}
inline Button::Button(std::string text, int font)
	: Button(text, font, UICompTool::color(ColorName::Green), UICompTool::color(ColorName::Green), UICompTool::color(ColorName::DarkGreen), UICompTool::color(ColorName::White))
{
}
inline Button::Button(std::string text, int font, int bgNormalColor, int bgOnmouseColor, int bgClickingColor, int frColor)
	: Button(text, font, bgNormalColor, bgOnmouseColor, bgClickingColor, frColor, { 70,70 }, Center, {100,100})
{
}
inline Button::Button(std::string text, int font, int bgNormalColor, int bgOnmouseColor, int bgClickingColor, int frColor, Vec2 pos, Part part, Vec2 size)
	:UIComponent(pos,part,size)
{
	_text = new Text(text, font, frColor, pos, part, size);
	_normal = new Box(bgNormalColor, pos, part, size);
	_onMouse = new Box(bgOnmouseColor, pos, part, size);
	_pushing = new Box(bgClickingColor, pos, part, size);
	myCompList.push_back(_text);
	myCompList.push_back(_normal);
	myCompList.push_back(_onMouse);
	myCompList.push_back(_pushing);
	_showing = _normal;
}
inline void Button::addActionListener(ActionListener * l)
{
	listenerList.push_back(l);
}

inline void Button::setPos(Vec2 pos, Part part)
{
	UIComponent::setPos(pos, part);
	for (UIComponent*c : myCompList) {
		c->setPos(pos, part);
	}
}

inline void Button::setSize(Vec2 size, Part part)
{
	UIComponent::setSize(size, part);
	for (UIComponent*c : myCompList) {
		c->setSize(size, part);
	}
}
