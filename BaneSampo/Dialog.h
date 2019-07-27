#pragma once
#include"Cakee/Layer.h"
#include<string>
#include"uicomp/Box.h"
#include"uicomp/Layouter.h"
#include"uicomp/Button.h"
#include"uicomp/ActionListener.h"
#include"Cakee/LayerManager.h"
#include"BSsystem.h"
class Dialog:public Layer,ActionListener {
protected:
	std::string _message;
	Box*bBack;
	Button*bOK;
	Text*tMessage;
public:
	inline Dialog(std::string message);
	inline void actionPerformed(std::string m);
	inline void update();
	inline void draw();
	inline bool canUndersUpdate() { return false; };
};
inline Dialog::Dialog(std::string message)
{
	_message = message;
	bBack = new Box(UICompTool::color(White),
		BSsystem::wndSize() / 2, Center, { 500,300 });
	tMessage=new Text(message,BSsystem::font(),
		UICompTool::color(ColorName::DarkBlue),
		bBack->getPos(_2),_2,
		{bBack->getSize().getX(),200}
	);
	bOK = new Button("OK", BSsystem::font(),
		UICompTool::color(ColorName::Blue),
		UICompTool::color(ColorName::DarkBlue),
		UICompTool::color(ColorName::DarkGreen),
		UICompTool::color(ColorName::White),
		bBack->getPos(_8) - Vec2({0,10}), _8,
		{ bBack->getSize().getX()/2,50}
	);
	bOK->addActionListener(this);
	bOK->getText()->setAlighment(Text::CENTER);
}

inline void Dialog::actionPerformed(std::string m)
{
	LayerManager::inst()->requireDelete(this);
}

inline void Dialog::update()
{
	bOK->update();
}

inline void Dialog::draw()
{
	bBack->draw();
	tMessage->draw();
	bOK->draw();
}
