#include "Food.h"
#include"DxLib.h"
#include<random>
#include<string>
#include"../BSsystem.h"
int Food::getRandomColor()
{
	std::random_device seed_gen;
	std::mt19937 r(seed_gen());
	return GetColor(
		130 + r() % 120, 150 + r() % 70, 170 + r() % 30
	);
}

Food::Food(Vec2 pos, int r, int score,int color)
	:_pos(pos), _r(r), _color(color)
{
	_text = new Text(std::to_string(score), BSsystem::font(), UICompTool::color(Black), pos, Center, { r,r });
	_text->setAlighment(Text::CENTER);
}

void Food::draw()
{
	DrawCircle(_pos.getX(), _pos.getY(), _r, _color, TRUE);
	_text->draw();
}

bool Food::isCollideWidth(Ball * b)
{
	double dst2 = pow(_pos.getX() - b->getX(), 2) + pow(_pos.getY() - b->getY(), 2);
	double sumr2 = pow(_r + b->getR(), 2);
	return dst2 < sumr2;
}
