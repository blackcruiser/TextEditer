#ifndef _BASEFORMATTER_H_
#define _BASEFORMATTER_H_

#include "stdafx.h"
#include "BaseGlyph.h"

class BaseFormatter
{
public:
	BaseFormatter();
	~BaseFormatter();

	virtual void format(BaseGlyph *root) = 0;
};

#endif