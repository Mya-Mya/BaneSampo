#pragma once
#include"UIComponent.h"
#include<list>
class Layouter {
public:
	static const int TOP = 0;
	static const int CENTER = 1;
	static const int BOTTOM = 2;
	static const int LEFT = 3;
	static const int RIGHT = 4;
	static void evenSpaceHorizontally(
		int x1, int x2, int y
		, std::list<UIComponent*> cmpList
		,int verticalAlighment
		, bool leftSpace = false, bool rightSpace = false);
	static void evenSpaceVertically(
		int x, int y1, int y2
		, std::list<UIComponent*> cmpList
		, int horizontalAlighment
		, bool topSpace = false, bool botoomSpace = false);
};