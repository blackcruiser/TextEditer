#ifndef _DOCUMENTGLYPH_H_
#define _DOCUMENTGLYPH_H_

#include "stdafx.h"

#include "BaseGlyph.h"

class DocumentGlyph : public BaseGlyph
{
public:
	DocumentGlyph(BaseGlyph *parent);
	virtual ~DocumentGlyph();

	virtual void draw(HDC hDc, Rect boundBox);
	virtual void format();

private:
	int m_leftMargin, m_rightMargin, m_topMargin, m_bottomMargin, m_lineSpace;
};

#endif