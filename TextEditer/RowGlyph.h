#ifndef _ROWGLYPH_H_
#define _ROWGLYPH_H_

#include "stdafx.h"

#include "BaseGlyph.h"

class RowGlyph : public BaseGlyph
{
public:
	RowGlyph(BaseGlyph *parent);
	~RowGlyph();

	virtual void draw(HDC hdc);

private:
	int lineSpace, wordSpace;

};

#endif