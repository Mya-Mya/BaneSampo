#pragma once
#include"Vec2.h"
#include"Part.h"
class UIComponent {
private:
	Vec2 _halfSize;
protected:
	Vec2 _size;
	Vec2 _centerPos;
	Vec2 _TLPos;
	Vec2 _BRPos;
	inline void updateTLBRPoses();
public:
	inline UIComponent();
	inline UIComponent(Vec2 pos, Part part, Vec2 size);
	virtual void draw()=0;
	virtual void update()=0;
	inline virtual void setPos(Vec2 pos, Part part);
	inline Vec2 getPos(Part part);
	inline virtual void setSize(Vec2 size, Part part);
	inline Vec2 getSize();
};

UIComponent::UIComponent() 
	:UIComponent({ 60,30 }, Part::Center, {100,40})
{
}

UIComponent::UIComponent(Vec2 pos, Part part, Vec2 size) {
	setSize(size, part);
	setPos(pos, part);
}

void UIComponent::setPos(Vec2 newPos, Part part) {
	_centerPos = newPos;
	switch (part)
	{
	case TL:
		_centerPos.move(_halfSize.getX(), _halfSize.getY());
		break;
	case _2:
		_centerPos.move(0, _halfSize.getY());
		break;
	case _3:
		_centerPos.move(-_halfSize.getX(), _halfSize.getY());
		break;
	case _4:
		_centerPos.move(_halfSize.getX(), 0);
		break;
	case Center:
		break;
	case _6:
		_centerPos.move(-_halfSize.getX(), 0);
		break;
	case _7:
		_centerPos.move(_halfSize.getX(), -_halfSize.getY());
		break;
	case _8:
		_centerPos.move(0, -_halfSize.getY());
		break;
	case BR:
		_centerPos.move(-_halfSize.getX(), -_halfSize.getY());
		break;
	}
	updateTLBRPoses();
}

Vec2 UIComponent::getPos(Part part) {
	switch (part)
	{
	case TL:
		return _TLPos;
		break;
	case Center:
		return _centerPos;
		break;
	case BR:
		return _BRPos;
		break;
	}

	switch (part)
	{
	case _2:
		return Vec2(_centerPos.getX(), _TLPos.getY());
		break;
	case _3:
		return Vec2(_BRPos.getX(), _TLPos.getY());
		break;
	case _4:
		return Vec2(_TLPos.getX(), _centerPos.getY());
		break;
	case _6:
		return Vec2(_BRPos.getX(), _centerPos.getY());
		break;
	case _7:
		return Vec2(_TLPos.getX(), _BRPos.getY());
		break;
	case _8:
		return Vec2(_centerPos.getX(), _BRPos.getY());
		break;
	}
}

void UIComponent::setSize(Vec2 newSize, Part part) {
	if (_size == newSize)return;
	_halfSize = newSize / 2;
	//_sizeは古いサイズと認識するべし
	switch (part)
	{
	case TL:
		_centerPos += (newSize - _size) / 2;
		break;
	case _2:
		_centerPos.move(0, (newSize.getY() - _size.getY())/2);
		break;
	case _3:
		_centerPos.move((_size.getX() - newSize.getX()) / 2, (newSize.getY() - _size.getY()) / 2);
		break;
	case _4:
		_centerPos.move((newSize.getX() - _size.getX()) / 2, 0);
		break;
	case Center:
		break;
	case _6:
		_centerPos.move((_size.getX()- newSize.getX()) / 2, 0);
		break;
	case _7:
		_centerPos.move((newSize.getX() - _size.getX()) / 2, (_size.getY() - newSize.getY()) / 2);
		break;
	case _8:
		_centerPos.move(0, (_size.getY() - newSize.getY()) / 2);
		break;
	case BR:
		_centerPos-= (newSize - _size) / 2;
		break;
	}
	_size = newSize;
	updateTLBRPoses();
}

Vec2 UIComponent::getSize() {
	return _size;
}

void UIComponent::updateTLBRPoses() {
	_TLPos = _centerPos - _halfSize;
	_BRPos = _centerPos + _halfSize;
}