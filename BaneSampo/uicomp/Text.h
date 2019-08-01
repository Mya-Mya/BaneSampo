#pragma once
#include"UIComponent.h"
#include"UICompTool.h"
#include<string>
class Text :public UIComponent {
protected:
	std::string _text;
	int _font;
	int _alighment;
	Vec2 _textPos;
	int _color;
	inline void updateTextX();
	inline void updateTextY();
public:
	const static int LEFT = 0;
	const static int CENTER = 1;
	const static int RIGHT = 2;
	inline Text();
	inline Text(std::string text,int font);
	inline Text(std::string text,int font, int color);
	inline Text(std::string text,int font, int color,Vec2 pos, Part part, Vec2 size);
	inline void setText(std::string text);
	inline void setFont(int font);
	inline void setAlighment(int alighment);
	inline void setColor(int color);
	inline void setPos(Vec2 pos, Part part);
	inline void setSize(Vec2 size, Part part);
	inline std::string getText();
	inline void draw();
	inline void update();
};

inline Text::Text()
	:Text("uicomp::Text",0)
{
}

inline Text::Text(std::string text, int font)
	:Text(text,font,UICompTool::color(ColorName::Pink))
{
}

inline Text::Text(std::string text, int font, int color)
	:Text(text,font,color, { 70,70 }, Center, { 100,100 })
{
}

inline Text::Text(std::string text, int font, int color, Vec2 pos, Part part, Vec2 size)
	: UIComponent(pos,part,size)
{
	setText(text);
	setFont(font);
	setColor(color);
	setAlighment(LEFT);
}


inline void Text::setText(std::string text)
{
	_text = text;
	updateTextX();
}

inline void Text::setFont(int font)
{
	_font = font;
	updateTextY();
}
inline void Text::setAlighment(int alighment)
{
	_alighment = alighment;
	updateTextX();
}
inline void Text::setColor(int color)
{
	_color = color;
}
inline void Text::setPos(Vec2 pos, Part part)
{
	UIComponent::setPos(pos, part);
	updateTextX();
	updateTextY();
}
inline void Text::setSize(Vec2 size, Part part)
{
	UIComponent::setSize(size, part);
	updateTextX();
	updateTextY();
}
inline std::string Text::getText()
{
	return _text;
}
inline void Text::draw()
{
	DrawFormatStringToHandle(_textPos.getX(), _textPos.getY(),_color , _font, _text.c_str());
}
inline void Text::update()
{
}
inline void Text::updateTextX()
{
	if (_alighment != RIGHT&&_alighment != CENTER) {
		_textPos.setX(getPos(Part::TL).getX());
		return;
	}

	int sx=GetDrawStringWidthToHandle(_text.c_str(), _text.size(), _font);
	switch (_alighment)
	{
	case RIGHT:
		_textPos.setX(getPos(Part::BR).getX() - sx);
		break;
	case CENTER:
		_textPos.setX(getPos(Part::Center).getX() - sx / 2);
		break;
	}
}

inline void Text::updateTextY()
{
	_textPos.setY(getPos(Part::Center).getY() - GetFontSizeToHandle(_font) / 2);
}
