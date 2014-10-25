#ifndef _PARAGRAPHGLYPH_H_
#define _PARAGRAPYGLYPH_H_

#include "stdafx.h"
#include "BaseGlyph.h"
#include "RowFormat.h"

class ParagraphGlyph : public BaseGlyph
{
public:
	ParagraphGlyph(BaseGlyph *parent);
	virtual ~ParagraphGlyph();

private:
	RowFormat *m_rowFormat;


};

#endif