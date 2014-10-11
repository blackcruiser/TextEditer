#ifndef _BASEFORMATTER_H_
#define _BASEFORMATTER_H_

#include "stdafx.h"
#include "util.h"

#include <list>

class BaseGlyph;

class BaseFormatter
{
public:
	BaseFormatter();
	~BaseFormatter();

	virtual void formatDocument(std::list<BaseGlyph *> child, Rect boundBox) = 0;
	virtual void formatRow(BaseGlyph *row, std::list<BaseGlyph *> &child) = 0;

};

#endif