#include "stdafx.h"
#include "DocumentGlyph.h"

DocumentGlyph::DocumentGlyph(BaseGlyph *parent) :
	BaseGlyph(parent)
{
}

DocumentGlyph::~DocumentGlyph()
{

}

void DocumentGlyph::draw(HDC hDc)
{
	for (std::list<BaseGlyph *>::iterator iter = m_child.begin(); iter != m_child.end(); iter++)
		(**iter).draw(hDc);
}

void DocumentGlyph::format()
{
	if (m_pFormatter != NULL)
		m_pFormatter->format(m_child);
}