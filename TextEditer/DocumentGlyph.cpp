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

}

void DocumentGlyph::draw(HDC hDc, Rect boundBox)
{

}

void DocumentGlyph::format()
{

}