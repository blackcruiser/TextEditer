#ifndef _DOCUMENTGLYPH_H_
#define _DOCUMENTGLYPH_H_

#include "stdafx.h"

#include "BaseGlyph.h"
#include "BaseCompositor.h"

class DocumentGlyph : public BaseGlyph
{
public:
	DocumentGlyph(BaseGlyph *parent);
	virtual ~DocumentGlyph();
	static DocumentGlyph *createEmptyDoc();

	void setCompositor(BaseCompositor *compositor);
	BaseGlyph *compose(Graphics *g);
	virtual void draw(Graphics *g);


private:
	BaseCompositor *m_compositor;
	
};

#endif