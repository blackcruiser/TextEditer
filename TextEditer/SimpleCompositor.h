#ifndef _SIMPLECOMPOSITOR_H_
#define _SIMPLECOMPOSITOR_H_

#include "stdafx.h"
#include "BaseCompositor.h"
#include "ParagraphGlyph.h"

class SimpleCompositor : public BaseCompositor
{
public:
	//SimpleCompositor();
	//~SimpleCompositor();

	virtual BaseGlyph *compose(Graphics *g, BaseGlyph *document);
	void createPage(Graphics *g, BaseGlyph *document, std::list<BaseGlyph *> &pageList);
	void createRow(Graphics *g, BaseGlyph *paragraph, std::list<BaseGlyph *> &rowList);
};

#endif