#ifndef _DOCUMENTGLYPH_H_
#define _DOCUMENTGLYPH_H_

#include "stdafx.h"

#include "BaseGlyph.h"
#include "BaseCompositor.h"
#include "PageFormat.h"

class DocumentGlyph : public BaseGlyph
{
public:
	DocumentGlyph(BaseGlyph *parent);
	DocumentGlyph();
	virtual ~DocumentGlyph();
	static DocumentGlyph *createEmptyDoc();

	PageFormat *setPageFormat(PageFormat *pageFormat);
	PageFormat *getPageFormat();

	void setCompositor(BaseCompositor *compositor);
	BaseGlyph *compose(Graphics *g);


private:
	BaseCompositor *m_compositor;
	PageFormat *m_pageFormat;

	
};

#endif