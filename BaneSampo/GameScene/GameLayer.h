#pragma once
#include"../Cakee/Layer.h"
#include"../uicomp/Vec2.h"
#include"../uicomp/Text.h"
#include"../BSsystem.h"
#include<list>
#include"Ball.h"
#include"Food.h"
#include<random>
#include"Warning.h"

class GameLayer :public Layer {
protected:
	std::mt19937 random;
	int *_m;
	int *_r;
	double *_k;
	double *_l;
	std::list<Ball*>balls;
	Ball*cursorBall;
	Food *food;

	void bindBalls(Ball*b1, Ball*b2, double *k, double *l);
	int score = 0;
	Warning *warning;
	Text*tScore;
public:
	GameLayer();
	void update();
	void draw();
	inline bool canUndersUpdate() { return true; }
};