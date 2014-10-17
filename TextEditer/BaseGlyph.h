#ifndef _BASEGLYPH_H_
#define _BASEGLYPH_H_

#include "stdafx.h"
#include "util.h"

#include "BaseCompositor.h"

#include <list>

class BaseGlyph 
{
public:
	BaseGlyph(BaseGlyph *parent);
	virtual ~BaseGlyph();

	BaseGlyph *getParent();
	void addChild(BaseGlyph *child, int index);
	void deleteChild(BaseGlyph *child);
	void clearChild();
	BaseGlyph* getChild(int index);
    int getChildNum();

    void setCompositor(BaseCompositor *compositor);
	void compose();

	Rect getBoundBox();

	virtual void draw(HDC hdc, Rect boundBox) = 0;

protected:
	BaseGlyph *m_parent;
	std::list<BaseGlyph *> m_child;
    BaseCompositor *m_compositor;

	Rect m_boundBox;
};

#endif
