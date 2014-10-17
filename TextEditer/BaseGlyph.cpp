#include "stdafx.h"
#include "BaseGlyph.h"

BaseGlyph::BaseGlyph(BaseGlyph *parent):
	m_parent(parent)
{
}

BaseGlyph::~BaseGlyph()
{

}

BaseGlyph * BaseGlyph::getParent()
{
	return m_parent;
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
}

int BaseGlyph::getChildNum()
{
    return m_child.size();
}

void BaseGlyph::clearChild()
{
	m_child.clear();
}

void BaseGlyph::setCompositor(BaseCompositor *compositor)
{
	m_compositor = compositor;
}

void BaseGlyph::compose()
{
	if (m_compositor != NULL)
		m_compositor->compose(this);
	else
		throw _T("BaseGlyph::compose : m_compositor == NULL");
}

Rect BaseGlyph::getBoundBox()
{
	return m_boundBox;
}
