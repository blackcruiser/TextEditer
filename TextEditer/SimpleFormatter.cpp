#include "stdafx.h"
#include "SimpleFormatter.h"

SimpleFormatter::SimpleFormatter()
{

}

SimpleFormatter::~SimpleFormatter()
{

}

void SimpleFormatter::format(std::list<BaseGlyph *> child)
{
	std::list<BaseGlyph *>::iterator iter;

	for (iter = child.begin(); iter != child.end(); iter++)

}