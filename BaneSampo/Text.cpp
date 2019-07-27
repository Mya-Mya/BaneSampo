#include"uicomp\Text.h"

Text::Text()
	:Text("uicomp::Text", 0)
{
}
Text::Text(std::string text, int font)
	:Text(text,font,UICompTool::color(ColorName::Pink))
{
}

Text::Text(std::string text, int font, int color)
	:Text(text,font,color, { 70,70 }, Center, { 100,100 })
{
}

Text::Text(std::string text, int font, int color, Vec2 pos, Part part, Vec2 size)
	: UIComponent(pos,part,size)
{
	setText(text);
	setFont(font);
	setColor(color);
	setAlighment(LEFT);
}
void Text::setText(std::string text)
{
	_text = text;
	updateTextX();
}

void Text::setFont(int font)
{
	_font = font;
	updateTextY();
}

void Text::setAlighment(int alighment)
{
	_alighment = alighment;
	updateTextX();
}

void Text::setColor(int color)
{
	_color = color;
}

void Text::setPos(Vec2 pos, Part part)
{
	UIComponent::setPos(pos, part);
	updateTextX();
	updateTextY();
}

void Text::setSize(Vec2 size, Part part)
{
	UIComponent::setSize(size, part);
	updateTextX();
	updateTextY();
}

std::string Text::getText()
{
	return _text;
}

void Text::draw()
{
	DrawFormatStringToHandle(_textPos.getX(), _textPos.getY(),_color , _font, _text.c_str());
}

void Text::updateTextX()
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

void Text::updateTextY()
{
	_textPos.setY(getPos(Part::Center).getY() - GetFontSizeToHandle(_font) / 2);
}