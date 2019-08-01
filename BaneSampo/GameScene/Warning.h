#pragma once
#include"../uicomp/Text.h"
#include<string>
#include"../BSsystem.h"
#include"DxLib.h"
class Warning {
protected:
	Text *_tMessage;
	double deltaTheta = 0.1;
	double theta = 0;
	int _color;
public:
	inline Warning(std::string message) {
		int bigFont = CreateFontToHandle("ƒƒCƒŠƒI", 100, 5, DX_FONTTYPE_ANTIALIASING);
		_tMessage = new Text(message, bigFont, UICompTool::color(White), BSsystem::wndSize() / 2, Center, { 700,300 });
		_tMessage->setAlighment(Text::CENTER);
		_color = UICompTool::color(Red);
	
	};
	inline void draw() {
		theta += deltaTheta;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 140 + 60 * cos(theta));
		DrawBox(0, 0, BSsystem::wndSize().getX(), BSsystem::wndSize().getY(), _color, TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		_tMessage->draw();
	}

};