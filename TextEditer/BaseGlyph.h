#ifndef _BASEGLYPH_H_
#define _BASEGLYPH_H_

#include "stdafx.h"

#include <cstddef>
#include <list>

class BaseGlyph 
{
public:
	BaseGlyph(BaseGlyph *parent);
	~BaseGlyph();

	void addChild(BaseGlyph *child);
	virtual void draw(HDC hdc) = 0;

protected:
	BaseGlyph *_parent;
	std::list<BaseGlyph *> _child;
};

#endif