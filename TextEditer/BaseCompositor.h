#ifndef _BASECOMPOSITOR_H_
#define _BASECOMPOSITOR_H_

#include "Graphics.h"
#include "DocumentGlyph.h"

#include <list>

class BaseCompositor
{
public:
	virtual BaseGlyph *compose(Graphics *g, DocumentGlyph *doucment) = 0;
};

#endif