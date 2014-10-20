#ifndef _BASECOMPOSITOR_H_
#define _BASECOMPOSITOR_H_

/*
* forward declaration class BaseGlyph
*/
class BaseGlyph;

class BaseCompositor
{
public:
	virtual void compose(Grapyics g, BaseGlyph *glyph) = 0;


};

#endif