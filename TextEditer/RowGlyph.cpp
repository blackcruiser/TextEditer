#include "stdafx.h"
#include "RowGlyph.h"

RowGlyph::RowGlyph(BaseGlyph *parent):
	BaseGlyph(parent), m_wordSpace(10)
{

}

RowGlyph::~RowGlyph()
{

}

void RowGlyph::draw(Graphics *g)
{
	int x, y;

	g->getCurPox(x, y);
	for (std::list<BaseGlyph *>::iterator iter = m_child.begin(); iter != m_child.end(); iter++)
	{
		
	}
}