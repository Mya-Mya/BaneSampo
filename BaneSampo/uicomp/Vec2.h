#pragma once
#pragma warning(disable:4244)
class Vec2
{
private:
	int _x;
	int _y;
public:
	Vec2(int x, int y);
	Vec2();
	int getX() { return _x; }
	int getY() { return _y; }
	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
	void move(int dx, int dy);
	void operator*=(double ratio);
	void operator/=(double ratio);
	bool operator==(Vec2 v);
	void operator+=(Vec2 v);
	void operator-=(Vec2 v);
	void operator=(Vec2 v);
	Vec2 operator*(double ratio);
	Vec2 operator/(double ratio);
	Vec2 operator+(Vec2 x);
	Vec2 operator-(Vec2 x);

	~Vec2();
};