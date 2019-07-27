#include "Layouter.h"

void Layouter::evenSpaceHorizontally(int x1, int x2, int y, std::list<UIComponent*>cmpList,int verticalAlighment, bool leftSpace, bool rightSpace)
{
	int lineWidth = abs(x2 - x1);
	int sumWidth = 0;
	for (UIComponent*c : cmpList) {
		sumWidth += c->getSize().getX();
	}
	double spaceWidth = (double)(lineWidth - sumWidth)
		/ (double)(cmpList.size() - 1 + (leftSpace ? 1 : 0) + (rightSpace ? 1 : 0));

	Part targetPart;
	switch (verticalAlighment)
	{
	case TOP:
		targetPart = Part::TL;
		break;
	case BOTTOM:
		targetPart = Part::_7;
		break;
	case CENTER:
	default:
		targetPart = Part::_4;
	}
	double nowX = leftSpace ? spaceWidth+x1 : x1;
	for (auto i = cmpList.begin(); i != cmpList.end(); i++) {
		(*i)->setPos({ (int)nowX,y }, targetPart);
		nowX += (*i)->getSize().getX() + spaceWidth;
	}

}

void Layouter::evenSpaceVertically(int x, int y1, int y2, std::list<UIComponent*> cmpList, int horizontalAlighment, bool topSpace, bool bottomSpace)
{
	int lineHeight = abs(y2 - y1);
	int sumHeight = 0;
	for (UIComponent*c : cmpList) {
		sumHeight += c->getSize().getY();
	}
	double spaceHeight = (double)(lineHeight - sumHeight)
		/ (double)(cmpList.size() - 1 + (topSpace ? 1 : 0) + (bottomSpace ? 1 : 0));

	Part targetPart;
	switch (horizontalAlighment)
	{
	case LEFT:
		targetPart = Part::TL;
		break;
	case RIGHT:
		targetPart = Part::_3;
		break;
	case CENTER:
	default:
		targetPart = Part::_2;
	}
	double nowY = topSpace ? spaceHeight + y1 : y1;
	for (auto i = cmpList.begin(); i != cmpList.end(); i++) {
		(*i)->setPos({ x,(int)nowY }, targetPart);
		nowY += (*i)->getSize().getY() + spaceHeight;
	}
}
