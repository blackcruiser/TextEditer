#include "stdafx.h"
#include "SimpleFormatter.h"

SimpleFormatter::SimpleFormatter()
{

}

SimpleFormatter::~SimpleFormatter()
{

}

void SimpleFormatter::formatDocument(std::list<BaseGlyph *> child, Rect boundBox)
{
	std::list<BaseGlyph *>::iterator iter;
	Rect cBoundBox;

	for (iter = child.begin(); iter != child.end(); iter++)
	{
		cBoundBox = (*iter)->getBoundBox();
		if (cBoundBox.width + cBoundBox.x > cBoundBox.width)
			(*iter)->format();
	}
}

void SimpleFormatter::formatRow(std::list<BaseGlyph *> child, Rect boundBox)
{
	std::list<BaseGlyph *>::iterator iter;
	Rect cBoundBox;
	int totWidth;
	bool isExceededBoundry;

	totWidth = 0;
	for (iter = child.begin(); iter != child.end(); iter++)
	{
		cBoundBox = (*iter)->getBoundBox();

		totWidth += cBoundBox.width;
		if (totWidth > boundBox.width)

	}
}