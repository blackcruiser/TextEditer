#include "stdafx.h"
#include "BaseGlyph.h"

BaseGlyph::BaseGlyph(BaseGlyph *parent):
	m_parent(parent)
{
}

BaseGlyph::BaseGlyph():
	m_parent(NULL)
{

}

BaseGlyph::~BaseGlyph()
{

}

BaseGlyph *BaseGlyph::getParent()
{
	return m_parent;
}

void BaseGlyph::setParent(BaseGlyph *parent)
{
	m_parent = parent;
}
/*
 * insert a child glyph before index 
 * if index = -1, insert in the end
 */
void BaseGlyph::addChild(BaseGlyph *child, int index)
{
	int count = 0; 
	std::list<BaseGlyph *>::iterator iter;

    if (index == -1)
    {
        m_child.push_back(child);
        return;
    }

    for (iter = m_child.begin(); iter != m_child.end(); iter++, count++) 
    {
       if (count == index)
       {
           m_child.insert(iter, child);
       }
    }
}

void BaseGlyph::deleteChild(BaseGlyph *child)
{
	m_child.remove(child);
}

BaseGlyph *BaseGlyph::getChild(int index)
{
	int count = 0;
	std::list<BaseGlyph *>::iterator iter;

    for (iter = m_child.begin(); iter != m_child.end(); iter++, count++)
    {
        if (count == index)
        {
            return *iter;
        }
    }

	return NULL;
}

int BaseGlyph::getChildNum()
{
    return m_child.size();
}

void BaseGlyph::clearChild()
{
	m_child.clear();
}

BaseIterator *BaseGlyph::createIterator()
{
	BaseIterator *iter;

	iter = new BaseIterator();
	iter->setContainer(&m_child);
	return iter;
}

void BaseGlyph::setLoc(FzRect &rect)
{
	m_locRect.x = rect.x;
	m_locRect.y = rect.y;
	m_locRect.width = rect.width;
	m_locRect.height = rect.height;
}

void BaseGlyph::getLoc(FzRect &rect)
{
	rect.x = m_locRect.x;
	rect.y = m_locRect.y;
	rect.width = m_locRect.width;
	rect.height = m_locRect.height;
}

void BaseGlyph::getBound(Graphics *g, FzRect &rect)
{
	throw _T("draw : unsupport operation!");
}

void BaseGlyph::draw(Graphics *g, int x, int y)
{
	throw _T("draw : unsupport operation!");
}