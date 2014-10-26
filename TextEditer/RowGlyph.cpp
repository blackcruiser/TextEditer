#include "stdafx.h"
#include "RowGlyph.h"

RowGlyph::RowGlyph(BaseGlyph *parent):
	BaseGlyph(parent), m_format(NULL)
{

}

RowGlyph::RowGlyph() :
m_format(NULL)
{

}

RowGlyph::~RowGlyph()
{

}

void RowGlyph::setFormat(RowFormat *format)
{
	m_format = format;
}

void RowGlyph::setHeight(int height)
{
	m_height = height;
}

void RowGlyph::getBound(Graphics *g, FzRect &rect)
{
	rect.width = m_format->getWidth();
	rect.height = m_height;
}

void RowGlyph::draw(Graphics *g, int x, int y)
{
	BaseGlyph *glyph;
	BaseIterator *iter;
	FzRect rect;
	int sx, sy;

	sx = x + m_format->getLeftIndent();
	sy = y + m_format->getRowSpace();
	iter = createIterator();
	for (iter->init(); !iter->isEnd(); iter->next())
	{
		glyph = iter->getValue();

		glyph->draw(g, sx, sy);
		glyph->getBound(g, rect);
		sx += rect.width + m_format->getWordSpace();
	}
}