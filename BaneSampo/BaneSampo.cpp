#include<DxLib.h>
#include <iostream>
#include"BSsystem.h"
#include"Cakee\LayerManager.h"
#include"uicomp\Mouse.h"
#include"MenuLayer.h"
#include"GameLayer.h"
#include"Keyboard.h"
int main()
{
	SetGraphMode(BSsystem::wndSize().getX(), BSsystem::wndSize().getY(), 16);
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	LayerManager*l = LayerManager::inst();
	Mouse*m = Mouse::Instance();
	l->addLayer(nullptr, new GameLayer(), StackingMode::Top);
	while(ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		Keyboard_Update();
		m->Update();
		l->mainLoop();
	}
	DxLib_End();
	return 0;
}