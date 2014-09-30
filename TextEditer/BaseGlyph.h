#ifndef _BASEGLYPH_H_
#define _BASEGLYPH_H_

#include "stdafx.h"

#include <cstddef>

class BaseGlyph;

struct ChildList
{
	BaseGlyph *item;
	ChildList *next;
};

class BaseGlyph 
{
public:
	BaseGlyph(BaseGlyph *_parent);
	~BaseGlyph();

	virtual void draw(HDC hdc) = 0;

private:
	BaseGlyph *parent;
	ChildList *childHead;
};

#endif