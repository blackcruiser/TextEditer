#ifndef _BASECOMPOSITOR_H_
#define _BASECOMPOSITOR_H_

/*
* forward declaration class BaseGlyph
*/
class BaseGlyph;

class BaseCompositor
{
public:
	virtual void compose(BaseGlyph *glyph);


};

#endif