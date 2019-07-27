#pragma once
#include"UIComponent.h"
#include"UICompTool.h"
#include<string>
#pragma warning(disable:4267)
class Text :public UIComponent {
protected:
	std::string _text;
	int _font;
	int _alighment;
	Vec2 _textPos;
	int _color;
	void updateTextX();
	void updateTextY();
public:
	const static int LEFT = 0;
	const static int CENTER = 1;
	const static int RIGHT = 2;
	Text();
	Text(std::string text,int font);
	Text(std::string text,int font, int color);
	Text(std::string text,int font, int color,Vec2 pos, Part part, Vec2 size);
	void setText(std::string text);
	void setFont(int font);
	void setAlighment(int alighment);
	void setColor(int color);
	void setPos(Vec2 pos, Part part);
	void setSize(Vec2 size, Part part);
	std::string getText();
	void draw();
	inline void update() {};
};