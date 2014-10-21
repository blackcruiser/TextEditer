#ifndef _BASEGLYPH_H_
#define _BASEGLYPH_H_

#include "stdafx.h"
#include "BaseCompositor.h"
#include "Graphics.h"

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

	virtual void draw(Graphics *g);

protected:
	BaseGlyph *m_parent;
	std::list<BaseGlyph *> m_child;
    BaseCompositor *m_compositor;
};

#endif
