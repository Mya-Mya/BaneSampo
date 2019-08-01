#include "Button.h"

void Button::update()
{
	static Mouse*inst = Mouse::Instance();
	int pressingCnt = inst->GetPressingCount(Mouse::LEFT);
	int releasingCnt = inst->GetReleasingCount(Mouse::LEFT);
	
	int x = inst->GetX(); 
	int y = inst->GetY();
	if (_TLPos.getX() <= x&&x <= _BRPos.getX()&&_TLPos.getY() <= y&&y <= _BRPos.getY()) {
		if (releasingCnt == 1 && _isPushing) {
			for (auto i : listenerList)i->actionPerformed(_text->getText());
		}
		if (pressingCnt == 1)
			_isPushing = true;

		if (pressingCnt > 0)
			_showing = _pushing;
		else _showing = _onMouse;

	}
	else _showing = _normal;
}

void Button::draw()
{
	_showing->draw();
	_text->draw();
}

inline Text * Button::getText()
{
	return _text;
}

inline Box * Button::getNormalBox()
{
	return _normal;
}

inline Box * Button::getOnMouseBox()
{
	return _onMouse;
}

inline Box * Button::getPushingBox()
{
	return _pushing;
}
