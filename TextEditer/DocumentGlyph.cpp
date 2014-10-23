#include "stdafx.h"
#include "DocumentGlyph.h"
#include "ParagraphGlyph.h"

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
	ParagraphGlyph *paragraph = new ParagraphGlyph(doc);

	doc->addChild(paragraph, 0);

	return doc;

}

void DocumentGlyph::draw(Graphics *g)
{

}

void DocumentGlyph::format()
{

}