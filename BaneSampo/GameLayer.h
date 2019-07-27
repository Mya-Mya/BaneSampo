#pragma once
#include"Cakee/Layer.h"
#include"uicomp/Vec2.h"
#include<list>
#include"uicomp/Text.h"
#include"BSsystem.h"
#include"Ball.h"

class GameLayer :public Layer {
protected:
	Text*tScore;
	std::list<Ball*>balls;
	Ball*cursorBall;
	void bindBalls(Ball*b1, Ball*b2, double k, double l);
public:
	GameLayer();
	void update();
	void draw();
	inline bool canUndersUpdate() { return true; }
};