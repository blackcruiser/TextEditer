#include "stdafx.h"
#include "DocumentGlyph.h"

DocumentGlyph::DocumentGlyph(BaseGlyph *parent) :
	BaseGlyph(parent), m_leftMargin(10), m_rightMargin(0), m_topMargin(0), m_bottomMargin(0), m_lineSpace(0)
{
}

DocumentGlyph::~DocumentGlyph()
{

}

void DocumentGlyph::draw(HDC hDc, Rect boundBox)
{
	Rect cBoundBox;

	cBoundBox = { m_leftMargin, m_topMargin, 0, 0 };
	for (std::list<BaseGlyph *>::iterator iter = m_child.begin(); iter != m_child.end(); iter++)
	{
		(**iter).draw(hDc, cBoundBox);
		cBoundBox.y += (*iter)->getBoundBox().height + m_lineSpace;
	}
}

void DocumentGlyph::format()
{
	if (m_pFormatter != NULL)
		m_pFormatter->formatDocument(m_child, getBoundBox());
}