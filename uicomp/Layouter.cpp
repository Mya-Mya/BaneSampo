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
	int nowX = leftSpace ? spaceWidth+x1 : x1;
	for (auto i = cmpList.begin(); i != cmpList.end(); i++) {
		(*i)->setPos({ nowX,y }, targetPart);
		nowX += (*i)->getSize().getX() + spaceWidth;
	}

}
