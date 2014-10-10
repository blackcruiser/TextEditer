#ifndef _BASEGLYPH_H_
#define _BASEGLYPH_H_

#include "stdafx.h"
#include "util.h"
#include "BaseFormatter.h"

#include <list>

class BaseGlyph 
{
public:
	BaseGlyph(BaseGlyph *parent);
	~BaseGlyph();

	BaseGlyph *getParent();
	void addChild(BaseGlyph *child);
	void deleteChild();
	void addFormatter(BaseFormatter *formatter);
	BaseFormatter *deleteFormatter();
	Rect getBoundBox();

	virtual void format() = 0;
	virtual void draw(HDC hdc) = 0;

protected:
	BaseGlyph *m_parent;
	std::list<BaseGlyph *> m_child;
	Rect m_boundBox;
	BaseFormatter *m_pFormatter;
};

#endif