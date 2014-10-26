#ifndef _ROWGLYPH_H_
#define _ROWGLYPH_H_

#include "stdafx.h"
#include "BaseGlyph.h"
#include "RowFormat.h"

class RowGlyph : public BaseGlyph
{
public:
	RowGlyph(BaseGlyph *parent);
	RowGlyph();
	virtual ~RowGlyph();

	void setFormat(RowFormat *format);
	void setHeight(int height);

	virtual void getBound(Graphics *g, FzRect &rect);
	virtual void draw(Graphics *g, int x, int y);

private:
	RowFormat *m_format;
	int m_height;
};

#endif