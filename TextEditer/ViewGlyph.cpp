#include "stdafx.h"
#include "ViewGlyph.h"

ViewGlyph::ViewGlyph(BaseGlyph *parent) :
BaseGlyph(parent)
{

}

ViewGlyph::ViewGlyph()
{

}

ViewGlyph::~ViewGlyph()
{

}

void ViewGlyph::draw(Graphics *g, int x, int y)
{
	BaseIterator *iter;
	FzRect rect;
	int sx, sy;

	sx = x;
	sy = y;

	iter = createIterator();

	for (iter->init(); !iter->isEnd(); iter->next())
	{
		iter->getValue()->draw(g, sx, sy);

		iter->getValue()->getBound(g, rect);
		sy += rect.height;
	}
}