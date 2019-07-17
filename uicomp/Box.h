#pragma once
#include"UIComponent.h"
#include"UICompTool.h"
class Box :public UIComponent {
protected:
	int _color;
public:
	Box();
	Box(int color, Vec2 pos, Part part, Vec2 size);
	void setBgColor(int color);
	void draw();
	void update();
};