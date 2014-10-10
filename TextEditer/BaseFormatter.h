#ifndef _BASEFORMATTER_H_
#define _BASEFORMATTER_H_

#include "stdafx.h"
#include "BaseGlyph.h"

class BaseFormatter
{
public:
	BaseFormatter();
	~BaseFormatter();

	virtual void formatDocument(std::list<BaseGlyph *> child, Rect boundBox) = 0;
	virtual void formatRow(std::list<BaseGlyph *> child, Rect boundBox) = 0;

};

#endif