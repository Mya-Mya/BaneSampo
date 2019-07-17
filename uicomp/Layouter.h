#pragma once
#include"UIComponent.h"
#include<list>
class Layouter {
public:
	static const int TOP = 0;
	static const int CENTER = 1;
	static const int BOTTOM = 2;
	static void evenSpaceHorizontally(
		int x1, int x2, int y
		, std::list<UIComponent*>
		,int verticalAlighment
		, bool leftSpace = false, bool rightSpace = false);
};