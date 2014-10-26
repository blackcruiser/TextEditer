#include "stdafx.h"
#include "CharacterGlyph.h"

CharacterGlyph::CharacterGlyph(BaseGlyph *parent) :
BaseGlyph(parent)
{

}

CharacterGlyph::CharacterGlyph(TCHAR c, FzFont *font, FzSize *size, FzStyle *style) :
m_c(c), m_font(font), m_size(size), m_style(style)
{

}

CharacterGlyph::CharacterGlyph()
{

}

CharacterGlyph::~CharacterGlyph()
{

}


void CharacterGlyph::draw(Graphics *g, int x, int y)
{
	TCHAR szBuffer[2];

	szBuffer[0] = m_c;
	g->drawText(x, y, szBuffer, 1, m_font, m_size, m_style);
}

void CharacterGlyph::getBound(Graphics *g, FzRect &rect)
{
	TCHAR szBuffer[2];

	szBuffer[0] = m_c;
	g->getTextBound(szBuffer, 1, m_font, m_size, m_style, rect);
}