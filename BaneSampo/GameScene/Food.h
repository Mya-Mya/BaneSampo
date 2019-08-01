#pragma once
#include"../uicomp/Vec2.h"
#include"../uicomp/Text.h"
#include"Ball.h"
class Food {
protected:
	Text *_text;
	Vec2 _pos;
	int _r;
	int _color;
public:
	static int getRandomColor();
	Food(Vec2 pos, int r,int score) :Food(pos, r,score,getRandomColor()) {}
	Food(Vec2 pos, int r, int score,int color) ;
	void draw();
	bool isCollideWidth(Ball*b);
};