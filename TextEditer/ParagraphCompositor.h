#ifndef _PARAGRAPHCOMPOSITOR_H_
#define _PARAGRAPYCOMPOSITOR_H_

#include "BaseCompositor.h"

class ParagraphCompositor : public BaseCompositor
{
public:
	virtual void compose(Graphics *g, BaseGlyph *glyph);
};


#endif
