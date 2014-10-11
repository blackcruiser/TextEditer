#ifndef _ROWGLYPH_H_
#define _ROWGLYPH_H_

#include "stdafx.h"

#include "BaseGlyph.h"

class RowGlyph : public BaseGlyph
{
public:
	RowGlyph(BaseGlyph *parent);
	virtual ~RowGlyph();

	virtual void draw(HDC hdc, Rect boundBox);

private:
	int m_wordSpace;

};

#endif