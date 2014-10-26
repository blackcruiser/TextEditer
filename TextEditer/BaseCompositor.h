#ifndef _BASECOMPOSITOR_H_
#define _BASECOMPOSITOR_H_

#include "Graphics.h"

#include <list>

class BaseGlyph;

class BaseCompositor
{
public:
	virtual BaseGlyph *compose(Graphics *g, BaseGlyph *document) = 0;
};

#endif