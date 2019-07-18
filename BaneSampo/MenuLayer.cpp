#include "MenuLayer.h"
#include"DxLib.h"
#include"BSsystem.h"
#include"uicomp\Button.h"

MenuLayer::MenuLayer()
{
	Button*b;
	cmpList.push_back(new Box(UICompTool::color(Blue), { 0,90 }, Center, {100,20}));
	cmpList.push_back(new Box(UICompTool::color(Red), { 600,400 }, Center, {40,300}));
	cmpList.push_back(new Box(UICompTool::color(Green), { 700,300 }, Center, {120,200}));
	cmpList.push_back(b=new Button("‚±‚ñ‚É‚¿‚Í", BSsystem::font()
		, UICompTool::color(Green), UICompTool::color(YellowGreen), UICompTool::color(DarkBlue), UICompTool::color(White)
		, { 300,0 }, Center, { 200,100 })
		);

	Layouter::evenSpaceHorizontally(
		100, 700, 300,
		cmpList,
		Layouter::CENTER,
		false,
		false
	);
	b->addActionListener(this);
}

void MenuLayer::update()
{
	/*if (Mouse::Instance()->GetPressingCount(Mouse::LEFT) == 1) {
		static int i = 0;
		int a;
		if (i % 3 == 0)a = Layouter::CENTER;
		if (i % 3 == 1)a = Layouter::BOTTOM;
		if (i % 3 == 2)a = Layouter::TOP;
		Layouter::evenSpaceHorizontally(
			100, 700, 300,
			cmpList,
			a,
			(i/3)%2==0,
			(i/6)%2==0
		);
		i++;
	}*/
	for (auto i : cmpList)i->update();
}

void MenuLayer::draw()
{
	for (UIComponent* b : cmpList) {
		b->draw();
	}
	DrawLine(100, 300, 700, 300, UICompTool::color(White), 3);
}

void MenuLayer::actionPerformed(std::string message)
{
}
