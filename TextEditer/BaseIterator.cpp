#include "stdafx.h"
#include "BaseIterator.h"

void BaseIterator::setContainer(std::list<BaseGlyph *> *container)
{
	m_list = container;
}

void BaseIterator::init()
{
	m_iter = m_list->begin();
}

void BaseIterator::next()
{
	m_iter++;
}

BaseGlyph *BaseIterator::getValue()
{
	return *m_iter;
}

bool BaseIterator::isEnd()
{
	return m_iter == m_list->end();
}