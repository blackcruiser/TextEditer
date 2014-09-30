#include "stdafx.h"
#include "BaseGlyph.h"

BaseGlyph::BaseGlyph(BaseGlyph *_parent):
	parent(_parent), childHead(NULL) 
{
}

BaseGlyph::~BaseGlyph()
{

}