#include "MenuLayer.h"
#include"DxLib.h"
#include"BSsystem.h"


MenuLayer::MenuLayer()
{
	boxList.push_back(new Box(UICompTool::createColor(Blue), { 0,90 }, Center, {100,20}));
	boxList.push_back(new Box(UICompTool::createColor(Red), { 600,400 }, Center, {40,300}));
	boxList.push_back(new Box(UICompTool::createColor(Green), { 700,300 }, Center, {120,200}));
	boxList.push_back(new Box(UICompTool::createColor(Yellow), { 300,0 }, Center, {200,100}));
}

void MenuLayer::update()
{
	if (Mouse::Instance()->GetPressingCount(Mouse::LEFT) == 1) {
		static int i = 0;
		int a;
		if (i % 3 == 0)a = Layouter::CENTER;
		if (i % 3 == 1)a = Layouter::BOTTOM;
		if (i % 3 == 2)a = Layouter::TOP;
		Layouter::evenSpaceHorizontally(
			100, 700, 300,
			boxList,
			a,
			(i/3)%2==0,
			(i/6)%2==0
		);
		i++;
	}
}

void MenuLayer::draw()
{
	for (UIComponent* b : boxList) {
		b->draw();
	}
	DrawLine(100, 300, 700, 300, UICompTool::createColor(White), 3);
}
