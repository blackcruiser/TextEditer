#include "View.h"

View::View()
{
	m_document = new DocumentGlyph(NULL);

}

View::~View()
{
	delete m_document;
}

void View::draw(Graphics *g)
{
	m_document->draw(g);
}