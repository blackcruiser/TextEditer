#ifndef _PAGEGLYPH_H_
#define _PAGEGLYPH_H_

#include "stdafx.h"
#include "BaseGlyph.h"
#include "PageFormat.h"

class PageGlyph : public BaseGlyph
{
public:
	PageGlyph(BaseGlyph *parent);
	PageGlyph();
	~PageGlyph();

	void setFormat(PageFormat *format);

	virtual void getBound(Graphics *g, FzRect &rect);
	virtual void draw(Graphics *g, int x, int y);

private:
	PageFormat *m_format;
	
};

#endif