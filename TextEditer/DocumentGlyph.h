#ifndef _DOCUMENTGLYPH_H_
#define _DOCUMENTGLYPH_H_

#include "stdafx.h"

#include "BaseGlyph.h"
#include "BaseCompositor.h"
#include "PageFormat.h"
#include "FzCaret.h"

class DocumentGlyph : public BaseGlyph
{
public:
	DocumentGlyph(BaseGlyph *parent);
	DocumentGlyph();
	virtual ~DocumentGlyph();
	static DocumentGlyph *createEmptyDoc();

	void setCaret(Graphics *g, FzCaret *caret);

	PageFormat *setPageFormat(PageFormat *pageFormat);
	PageFormat *getPageFormat();

	void setCompositor(BaseCompositor *compositor);
	BaseGlyph *compose(Graphics *g);


private:
	BaseCompositor *m_compositor;
	PageFormat *m_pageFormat;
	FzCaret *m_caret;
	BaseGlyph *m_view;

	
};

#endif