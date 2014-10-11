#include "stdafx.h"
#include "RowGlyph.h"

RowGlyph::RowGlyph(BaseGlyph *parent):
	BaseGlyph(parent), m_wordSpace(10)
{

}

RowGlyph::~RowGlyph()
{

}

void RowGlyph::draw(HDC hdc, Rect boundBox)
{
	Rect cBoundBox;

	cBoundBox = { boundBox.x, boundBox.y, 0, 0 };
	for (std::list<BaseGlyph *>::iterator iter = m_child.begin(); iter != m_child.end(); iter++)
	{
		(*iter)->draw(hdc, cBoundBox);
		cBoundBox.y += m_wordSpace;
	}
}