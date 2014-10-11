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

void BaseGlyph::addChild(std::list<BaseGlyph *>::const_iterator pos, BaseGlyph *child)
{
	m_child.insert(pos, child);
	child->setPos(pos++);
}

void BaseGlyph::addChild(int pos, BaseGlyph *child)
{
	if (pos == 0)
		m_child.push_front(child);
	else if (pos == -1)
		m_child.push_back(child);
}

void BaseGlyph::deleteChild(BaseGlyph *child)
{
	m_child.remove(child);
}

void BaseGlyph::setPos(std::list<BaseGlyph *>::const_iterator pos)
{
	m_pos = pos;
}

std::list<BaseGlyph *>::const_iterator BaseGlyph::getPos()
{
	return m_pos;
}

void BaseGlyph::addFormatter(BaseFormatter *formatter)
{
	m_pFormatter = formatter;
}

BaseFormatter *BaseGlyph::deleteFormatter()
{
	BaseFormatter *temp;

	temp = m_pFormatter;
	m_pFormatter = NULL;
	return temp;
}

Rect BaseGlyph::getBoundBox()
{
	return m_boundBox;
}