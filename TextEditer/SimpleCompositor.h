#ifndef _SIMPLECOMPOSITOR_H_
#define _SIMPLECOMPOSITOR_H_

#include "stdafx.h"
#include "BaseCompositor.h"

class SimpleCompositor : public BaseCompositor
{
public:
	//SimpleCompositor();
	//~SimpleCompositor();

	virtual BaseGlyph *compose(Graphics *g, DocumentGlyph *document);
	void createPage(Graphics *g, DocumentGlyph *document);
	void createRow(Graphics *g, std::list<BaseGlyph *>::iterator iter);
};

#endif