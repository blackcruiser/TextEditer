#include "stdafx.h"
#include "DocumentGlyph.h"

DocumentGlyph::DocumentGlyph(BaseGlyph *parent) :
	BaseGlyph(parent)
{
}

DocumentGlyph::~DocumentGlyph()
{

}

DocumentGlyph *DocumentGlyph::createEmptyDoc()
{
	DocumentGlyph *doc = new DocumentGlyph(NULL);


	return doc;

}

void DocumentGlyph::setCompositor(BaseCompositor *compositor)
{
	m_compositor = compositor;
}

BaseGlyph *DocumentGlyph::compose(Graphics *g)
{
	return m_compositor->compose(g, createIterator());
}

void DocumentGlyph::draw(Graphics *g)
{

}