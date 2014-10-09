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

	BaseGlyph *getParent();
	void addChild(BaseGlyph *child);
	void deleteChild();

	virtual void draw(HDC hdc) = 0;

protected:
	BaseGlyph *m_parent;
	std::list<BaseGlyph *> m_child;
	Rect m_boundingBox;
};

#endif