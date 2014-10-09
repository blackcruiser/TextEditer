#include "stdafx.h"
#include "SimpleFormatter.h"

SimpleFormatter::SimpleFormatter()
{

}

SimpleFormatter::~SimpleFormatter()
{

}

void SimpleFormatter::format(BaseGlyph *root)
{
	for (std::list<BaseGlyph *>::iterator iter = root->_child.begin(); iter != root->_child.end(); iter++)
}