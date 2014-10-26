#ifndef _PARAGRAPHGLYPH_H_
#define _PARAGRAPYGLYPH_H_

#include "stdafx.h"
#include "BaseGlyph.h"
#include "RowFormat.h"

class ParagraphGlyph : public BaseGlyph
{
public:
	ParagraphGlyph(BaseGlyph *parent);
	ParagraphGlyph();
	virtual ~ParagraphGlyph();

	RowFormat *setRowFormat(RowFormat *rowFormat);
	RowFormat *getRowFormat();
private:
	RowFormat *m_rowFormat;


};

#endif