#include "Vec2.h"


Vec2::Vec2(int x, int y) :_x(x), _y(y)
{
}

Vec2::Vec2():_x(0),_y(0)
{
}



void Vec2::move(int dx, int dy)
{
	_x += dx;
	_y += dy;
}

void Vec2::operator*=(double ratio)
{
	_x *= ratio;
	_y *= ratio;
}

void Vec2::operator/=(double ratio)
{
	_x /= ratio;
	_y /= ratio;
}


bool Vec2::operator==(Vec2 v)
{
	return _x == v.getX() && _y == v.getY();
}


void Vec2::operator+=(Vec2 v)
{
	move(v.getX(), v.getY());
}


void Vec2::operator-=(Vec2 v)
{
	move(-v.getX(), -v.getY());
}


void Vec2::operator=(Vec2 v)
{
	_x = v.getX();
	_y = v.getY();
}

Vec2 Vec2::operator*(double ratio)
{
	return Vec2(_x*ratio,_y*ratio);
}

Vec2 Vec2::operator/(double ratio)
{
	return Vec2(_x/ratio,_y/ratio);
}

Vec2 Vec2::operator+(Vec2 x)
{
	return Vec2(_x+x._x,_y+x._y);
}

Vec2 Vec2::operator-(Vec2 x)
{
	return Vec2(_x-x._x,_y-x._y);
}


Vec2::~Vec2()
{
}