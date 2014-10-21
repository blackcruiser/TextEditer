#ifndef _DOCUMENTGLYPH_H_
#define _DOCUMENTGLYPH_H_

#include "stdafx.h"

#include "BaseGlyph.h"
#include "RowGlyph.h"

class DocumentGlyph : public BaseGlyph
{
public:
	DocumentGlyph(BaseGlyph *parent);
	virtual ~DocumentGlyph();

	static DocumentGlyph *createEmptyDoc();

	virtual void draw(Graphics *g);
	void format();

private:
	
	
};

#endif