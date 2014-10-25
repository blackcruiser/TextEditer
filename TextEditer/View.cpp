#include "stdafx.h"
#include "View.h"

View::View()
{
	m_document = DocumentGlyph::createEmptyDoc();
}

View::~View()
{
	delete m_document;
}

void View::draw(Graphics *g)
{
	g->moveTo(0, 0);
	m_document->draw(g);
}