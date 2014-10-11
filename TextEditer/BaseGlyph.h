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
	virtual ~BaseGlyph();

	BaseGlyph *getParent();
	void addChild(std::list<BaseGlyph *>::const_iterator pos, BaseGlyph *child);
	void addChild(int pos, BaseGlyph *child);
	void deleteChild(BaseGlyph *child);
	void setPos(std::list<BaseGlyph *>::const_iterator pos);
	std::list<BaseGlyph *>::const_iterator getPos();

	void addFormatter(BaseFormatter *formatter);
	BaseFormatter *deleteFormatter();

	Rect getBoundBox();

	virtual void format() = 0;
	virtual void draw(HDC hdc, Rect boundBox) = 0;

protected:
	BaseGlyph *m_parent;
	std::list<BaseGlyph *> m_child;
	std::list<BaseGlyph *>::const_iterator m_pos;

	Rect m_boundBox;

	BaseFormatter *m_pFormatter;

};

#endif