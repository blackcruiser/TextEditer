#include "stdafx.h"
#include "BaseGlyph.h"

BaseGlyph::BaseGlyph(BaseGlyph *parent):
	_parent(parent)
{
}

BaseGlyph::~BaseGlyph()
{

}

void BaseGlyph::addChild(BaseGlyph *child)
{
	_child.push_back(child);
}