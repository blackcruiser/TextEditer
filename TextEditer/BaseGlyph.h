#ifndef _BASEGLYPH_H_
#define _BASEGLYPH_H_

#include "stdafx.h"
#include "fzUtil.h"
#include "Graphics.h"
#include "BaseIterator.h"

#include <list>

class BaseGlyph 
{
public:
	BaseGlyph(BaseGlyph *parent);
	BaseGlyph();
	virtual ~BaseGlyph();

	BaseGlyph *getParent();
	void setParent(BaseGlyph *parent);

	void addChild(BaseGlyph *child, int index);
	void deleteChild(BaseGlyph *child);
	void clearChild();
	BaseGlyph* getChild(int index);
    int getChildNum();
	virtual BaseIterator *createIterator();

	virtual void getBound(Graphics *g, FzRect &rect);
	virtual void draw(Graphics *g, int x, int y);

private:
	BaseGlyph *m_parent;
	std::list<BaseGlyph *> m_child;
};

#endif
