#include "stdafx.h"
#include "ParagraphGlyph.h"

ParagraphGlyph::ParagraphGlyph(BaseGlyph *parent) :
BaseGlyph(parent), m_rowFormat(NULL)
{

}

ParagraphGlyph::ParagraphGlyph() :
m_rowFormat(NULL)
{

}

ParagraphGlyph::~ParagraphGlyph()
{

}

RowFormat *ParagraphGlyph::setRowFormat(RowFormat *rowFormat)
{
	RowFormat *temp;

	temp = m_rowFormat;
	m_rowFormat = rowFormat;
	return temp;
}

RowFormat *ParagraphGlyph::getRowFormat()
{
	return m_rowFormat;
}