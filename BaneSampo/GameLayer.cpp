#include "GameLayer.h"
#include"Keyboard.h"
#include"DxLib.h"
#include"Cakee/LayerManager.h"
#include"Dialog.h"
void GameLayer::bindBalls(Ball * b1, Ball * b2, double k, double l)
{
	b1->addBall(b2, k, l);
	b2->addBall(b1, k, l);
}

GameLayer::GameLayer()
{
	tScore = new Text("", BSsystem::font(), UICompTool::color(Green));
	tScore->setSize({ 200,100 },Center);
	tScore->setPos({ 0,BSsystem::wndSize().getY() }, _7);
	tScore->setText("‚±‚ñ‚É‚¿‚Í");
	cursorBall = new Ball({0,0},20, 10);
	Ball*b1 = new Ball({ 100,50 }, 20, 70);
	Ball*b2 = new Ball({ 200,100 }, 30, 20);
	Ball*b3 = new Ball({ 300,500 }, 70, 30);
	bindBalls(cursorBall, b1, 5, 140);
	bindBalls(b1, b2, 4, 150);
	bindBalls(b2, b3, 5, 100);

	balls.push_back(b1);
	balls.push_back(b2);
	balls.push_back(b3);
}

void GameLayer::update()
{
	for (Ball*b : balls)b->updateFAV();
	for (Ball*b : balls)b->updateP();
	int mX; int mY;
	GetMousePoint(&mX, &mY);
	cursorBall->setPByForce(mX,mY);
	if (Keyboard_Get(KEY_INPUT_ESCAPE) != 0)
		LayerManager::inst()->addLayer(
			this, new Dialog("‚ ‚Í‚Í‚Í‚Í‚Í‚Í‚Í‚Í"), StackingMode::Top
		);
}

void GameLayer::draw()
{
	for (Ball*b : balls)b->draw();
	cursorBall->draw();
	tScore->draw();
}
