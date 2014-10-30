#include "stdafx.h"
#include "DocumentGlyph.h"
#include "ParagraphGlyph.h"
#include "CharacterGlyph.h"

DocumentGlyph::DocumentGlyph(BaseGlyph *parent) :
BaseGlyph(parent), m_compositor(NULL), m_pageFormat(NULL), m_view(NULL)
{
}

DocumentGlyph::DocumentGlyph() :
m_compositor(NULL), m_pageFormat(NULL)
{

}

DocumentGlyph::~DocumentGlyph()
{

}

void DocumentGlyph::setCaret(Graphics *g, FzCaret *caret)
{
	m_caret = caret;
	m_caret->setPhysicDoc(this);
	m_caret->setLogicDoc(this->m_view);
	m_caret->setLoc(0, 0);
	m_caret->draw(g);
}

DocumentGlyph *DocumentGlyph::createEmptyDoc()
{
	DocumentGlyph *doc = new DocumentGlyph(NULL);
	PageFormat *pageFormat = new PageFormat(0, 0, 0, 0, 500, 500);
	ParagraphGlyph *paragraph = new ParagraphGlyph(doc);
	RowFormat *rowFormat = new RowFormat(200, 0, 0, 0, 0, 0);
	FzFont *font = new FzFont();
	FzSize *size = new FzSize();
	FzStyle *style = new FzStyle();

	doc->setPageFormat(pageFormat);
	doc->addChild(paragraph, -1);

	size->height = 20;
	paragraph->setRowFormat(rowFormat);

	for (int i = 0; i < 100; i++)
	{
		paragraph->addChild(new CharacterGlyph(_T('a'), font, size, style), -1);
	}

	return doc;
}

PageFormat *DocumentGlyph::setPageFormat(PageFormat *pageFormat)
{
	PageFormat *temp;
	
	temp = m_pageFormat;
	m_pageFormat = pageFormat;

	return temp;
}

PageFormat *DocumentGlyph::getPageFormat()
{
	return m_pageFormat;
}

void DocumentGlyph::setCompositor(BaseCompositor *compositor)
{
	m_compositor = compositor;
}

BaseGlyph *DocumentGlyph::compose(Graphics *g)
{
	if (m_view)
		delete m_view;
	m_view = m_compositor->compose(g, this);
	return m_view;
}