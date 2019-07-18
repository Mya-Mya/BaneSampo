#pragma once
#include"Cakee\Layer.h"

#include"uicomp\Text.h"
#include"uicomp\Mouse.h"
#include"uicomp\Box.h"
#include"uicomp\Layouter.h"
#include<list>
#include"uicomp\ActionListener.h"
class MenuLayer:public Layer,ActionListener
{
private:
	std::list<UIComponent*>cmpList;

public:
	MenuLayer();
	void update();
	void draw();
	inline bool canUndersUpdate() { return true; }
	void actionPerformed(std::string message);
};