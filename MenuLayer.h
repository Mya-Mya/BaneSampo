#pragma once
#include"Cakee\Layer.h"

#include"uicomp\Text.h"
#include"uicomp\Mouse.h"
#include"uicomp\Box.h"
#include"uicomp\Layouter.h"
#include<list>
class MenuLayer:public Layer
{
private:
	std::list<UIComponent*>boxList;
public:
	MenuLayer();
	void update();
	void draw();
	inline bool canUndersUpdate() { return true; }
};