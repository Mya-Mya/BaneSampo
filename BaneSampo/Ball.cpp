#include "Ball.h"
#include"uicomp/UICompTool.h"
void Ball::addBall(Ball * ball, double k, double l)
{
	neighborBalls.push_back(ball);
	neighborKs.push_back(k);
	neighborLs.push_back(l);
}

void Ball::updateFAV()
{
	double F;
	double Fx=0;
	double Fy=0;
	for (int i = 0; i < neighborBalls.size(); i++) {
		Ball*ball = neighborBalls[i];
		double k = neighborKs[i];
		double l = neighborLs[i];
		double dx = ball->px - px;
		double dy = ball->py - py;
		double d = sqrt(pow(dx, 2) + pow(dy, 2));
		F = (d - l)*k;
		double dOnF = F / d;
		Fx += dx*dOnF;
		Fy += dy*dOnF;
	}
	Fx -= vx * _u;
	Fy -= vy * _u;
	double ax = Fx / _m;
	double ay = Fy / _m;
	vx += ax * 0.016;
	vy += ay * 0.016;
	
}

void Ball::updateP()
{
	px += vx;
	py += vy;
}

void Ball::draw()
{
	DrawCircle(px,py, _r, _color, TRUE);
	for (int i = 0; i < neighborBalls.size(); i++) {
		Ball*ball = neighborBalls[i];
		DrawLine(px, py, ball->px, ball->py, UICompTool::color(White), neighborKs[i]*2);
	}
}
