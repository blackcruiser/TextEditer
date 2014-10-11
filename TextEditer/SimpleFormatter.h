#ifndef _SIMPLEFORMATTER_H_
#define _SIMPLEFORMATTER_H_

#include "stdafx.h"
#include "BaseFormatter.h"

class SimpleFormatter : public BaseFormatter
{
public:
	SimpleFormatter();
	~SimpleFormatter();

	virtual void formatDocument(std::list<BaseGlyph *> &child, Rect boundBox);
	virtual void formatRow(BaseGlyph *row, std::list<BaseGlyph *> &child);
};

#endif