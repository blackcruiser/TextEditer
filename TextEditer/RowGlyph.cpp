#include "stdafx.h"
#include "RowGlyph.h"

RowGlyph::RowGlyph(BaseGlyph *parent):
	BaseGlyph(parent), m_wordSpace(10)
{

}

RowGlyph::~RowGlyph()
{

}

void RowGlyph::draw(Graphics g)
{
	int x, y;

	x = g.getCurX();
	y = g.getCurY();

	for (std::list<BaseGlyph *>::iterator iter = m_child.begin(); iter != m_child.end(); iter++)
	{
		
		g.moveTo(x + , y + );
		g.setFont(font);
		g.setFont(size);
		g.setStyle(style);
		(*iter)->draw(Graphics g);
	}
}