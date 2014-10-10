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

void BaseGlyph::addChild(BaseGlyph *child)
{
	m_child.push_back(child);
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