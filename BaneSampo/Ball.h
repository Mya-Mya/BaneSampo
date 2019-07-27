#pragma once
#include"uicomp/Vec2.h"
#include<vector>
#include"DxLib.h"

class Ball {
protected:
	int _color;
	int _r;
	int _m;
	double _u=5;
	double vx = 0;
	double vy = 0;
	double px = 0;
	double py = 0;
	std::vector<Ball*>neighborBalls;
	std::vector<double>neighborKs;
	std::vector<double>neighborLs;
	static inline int mToColor(double m) {
		return GetColor(90 + m*0.7, 210 - m *2, 250 - m *1.5);
	}
public:
	inline Ball(Vec2 p,int r, int m) :px(p.getX()),py(p.getY()),_r(r){
		setM(m);
	};
	inline void setM(int m) {
		_m = m;
		_color = mToColor(m);
	}
	void addBall(Ball*ball, double k, double l);
	void updateFAV();
	void updateP();
	void draw();
	inline void setPByForce(int x, int y) { px = x; py = y; }//カーソルに追従するボールのみに使う
};