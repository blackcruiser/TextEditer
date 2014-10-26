#include "stdafx.h"
#include "PageGlyph.h"

PageGlyph::PageGlyph(BaseGlyph *parent):
BaseGlyph(parent)
{

}

PageGlyph::PageGlyph()
{

}

PageGlyph::~PageGlyph()
{

}

void PageGlyph::setFormat(PageFormat *format)
{
	m_format = format;
}

void PageGlyph::getBound(Graphics *g, FzRect &rect)
{
	rect.width = m_format->getWidth();
	rect.height = m_format->getHeight();
}

void PageGlyph::draw(Graphics *g, int x, int y)
{
	BaseIterator *iter;
	BaseGlyph *glyph;
	FzRect rect;
	int sx, sy;

	sx = x + m_format->getLeftMargin();
	sy = y + m_format->getTopMargin();

	iter = createIterator();
	for (iter->init(); !iter->isEnd(); iter->next())
	{
		glyph = iter->getValue();
		
		glyph->draw(g, sx, sy);
		glyph->getBound(g, rect);
		sy += rect.height;
	}
}