#ifndef _DOCUMENTGLYPH_H_
#define _DOCUMENTGLYPH_H_

#include "stdafx.h"

#include "BaseGlyph.h"

class DocumentGlyph : public BaseGlyph
{
public:
	DocumentGlyph(BaseGlyph *parent);
	~DocumentGlyph();

	virtual void draw(HDC hDc);

private:
};

#endif