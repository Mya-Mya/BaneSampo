#include "GameLayer.h"
#include"../Keyboard.h"
#include"DxLib.h"
#include"../Cakee/LayerManager.h"
#include"../Dialog.h"
#include<string>
void GameLayer::bindBalls(Ball * b1, Ball * b2, double *k, double *l)
{
	b1->addBall(b2, k, l);
	b2->addBall(b1, k, l);
}

GameLayer::GameLayer()
{
	std::random_device seeder;
	random.seed(seeder());

	tScore = new Text("", BSsystem::font(), UICompTool::color(Green));
	tScore->setSize({ 200,100 },Center);
	tScore->setPos({ 0,BSsystem::wndSize().getY() }, _7);
	tScore->setText(std::to_string(score));

	_m = new int(20);
	_r = new int(50);
	_k = new double(5);
	_l = new double(70);
	cursorBall = new Ball({0,0},_r,_m);
	Ball*b1 = new Ball({ 100,50 }, _r, _m);
	Ball*b2 = new Ball({ 200,100 }, _r, _m);
	bindBalls(cursorBall, b1,_k, _l);
	bindBalls(b1, b2, _k, _l);

	balls.push_back(b1);
	balls.push_back(b2);

	food = new Food({ 50,50 }, 100,score);

	warning = new Warning("‚¢‚¸‚ê‚©‚Ìƒoƒl‚ÌF>Fmax");
}

void GameLayer::update()
{
	for (Ball*b : balls)b->updateFAV();
	for (Ball*b : balls)b->updateP();
	int mX; int mY;
	GetMousePoint(&mX, &mY);
	cursorBall->setPByForce(mX,mY);
	if (Keyboard_Get(KEY_INPUT_ESCAPE) != 0) {
		LayerManager::inst()->addLayer(
			this, new Dialog("‚ ‚Í‚Í‚Í‚Í‚Í‚Í‚Í‚Í"), StackingMode::Top
		);
		*_m += 20;
	}
	if (food == nullptr || food->isCollideWidth(balls.back())) {
		delete food;
		food = new Food({ 
			(int)(random()%BSsystem::wndSize().getX()),
			(int)(random()%BSsystem::wndSize().getY())}, 50,score);
		tScore->setText(std::to_string(score));
		score++;
	}
}

void GameLayer::draw()
{
	for (Ball*b : balls)b->draw();
	cursorBall->draw();
	tScore->draw();
	food->draw();
	warning->draw();
}
