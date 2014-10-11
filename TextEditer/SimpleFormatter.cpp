#include "stdafx.h"
#include "SimpleFormatter.h"
#include "CharacterGlyph.h"
#include "rowGlyph.h"

#include <typeinfo>

SimpleFormatter::SimpleFormatter()
{

}

SimpleFormatter::~SimpleFormatter()
{

}

void SimpleFormatter::formatDocument(std::list<BaseGlyph *> &child, Rect boundBox)
{
	std::list<BaseGlyph *>::iterator iter, flag;

	flag = child.end();
	for (iter = child.begin(); iter != child.end(); iter++)
	{
		if (typeid(*iter) == typeid(RowGlyph *))
		{
			if (flag != child.end())
			{
				for (flag; flag != iter; flag++)
					(*iter)->addChild(0, *flag);
				flag = child.end();

				(*iter)->format();
			}
			else
			{
				Rect cBoundBox = (*iter)->getBoundBox();
				if (cBoundBox.width + cBoundBox.x > cBoundBox.width)
					(*iter)->format();
			}
		}
		else if (typeid(*iter) == typeid(CharacterGlyph *))
		{
			if (flag != child.end())
				continue;
			else
				flag = iter;
		}
	}
}

void SimpleFormatter::formatRow(BaseGlyph *row, std::list<BaseGlyph *> &child)
{
	std::list<BaseGlyph *>::iterator iter;
	BaseGlyph *parent;
	Rect boundBox;
	int totWidth;
	bool isExceedBoundry;

	parent = row->getParent();
	boundBox = row->getBoundBox();

	totWidth = 0;
	isExceedBoundry = FALSE;

	for (iter = child.begin(); iter != child.end(); iter++)
	{
		Rect cBoundBox = (*iter)->getBoundBox();

		totWidth += cBoundBox.width;
		if (totWidth > boundBox.width)
		{
			isExceedBoundry = TRUE;
			break;
		}
	}
	
	if (isExceedBoundry)
	{
		std::list<BaseGlyph *>::const_iterator pos;

		pos = row->getPos() ++;

		for (; iter != child.end(); iter++)
			parent->addChild(pos, *iter);
	}
}