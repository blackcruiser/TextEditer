#ifndef _BASECOMPOSITOR_H_
#define _BASECOMPOSITOR_H_

#include "Graphics.h"
/*
* forward declaration class BaseGlyph
*/
class BaseGlyph;

class BaseCompositor
{
public:
	virtual void compose(Graphics *g, BaseGlyph *glyph) = 0;


};

#endif