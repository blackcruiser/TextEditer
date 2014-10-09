#ifndef _BASEFORMATTER_H_
#define _BASEFORMATTER_H_

#include "stdafx.h"

class BaseFormatter
{
public:
	BaseFormatter();
	~BaseFormatter();

	virtual void format() = 0;
};

#endif