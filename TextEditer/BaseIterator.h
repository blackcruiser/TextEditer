#ifndef _BASEITERATOR_H_
#define _BASEITERATOR_H_

#include "stdafx.h"
#include <list>

class BaseGlyph;

class BaseIterator
{
public:
	void setContainer(std::list<BaseGlyph *> *container);
	void init();
	void next();
	BaseGlyph *getValue();
	bool isEnd();

private:
	std::list<BaseGlyph *> *m_list;
	std::list<BaseGlyph *>::iterator m_iter;
};

#endif