#include "stdafx.h"
#include "CharacterGlyph.h"

CharacterGlyph::CharacterGlyph(BaseGlyph *parent):
	BaseGlyph(parent)
{
}


CharacterGlyph::~CharacterGlyph()
{

}


void CharacterGlyph::draw(Graphics g)
{
	g.drawText(m_c);
}