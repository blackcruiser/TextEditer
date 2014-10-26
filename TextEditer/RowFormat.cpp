#include "stdafx.h"
#include "RowFormat.h"

RowFormat::RowFormat()
{
}

RowFormat::~RowFormat()
{

}

RowFormat::RowFormat(int width, int leftIndent, int rightIndent, int firstRowIndent, int rowSpace, int wordSpace) :
m_width(width), m_leftIndent(leftIndent), m_rightIndent(rightIndent), m_firstRowIndent(firstRowIndent), m_rowSpace(rowSpace), m_wordSpace(wordSpace)
{

}

int RowFormat::getWidth()
{
	return m_width;
}

void RowFormat::setWidth(int width)
{
	m_width = width;
}

int RowFormat::getLeftIndent()
{
	return m_leftIndent;
}

void RowFormat::setLeftIndent(int indent)
{
	m_leftIndent = indent;
}

int RowFormat::getRightIndent()
{
	return m_rightIndent;
}

void RowFormat::setRightIndent(int indent)
{
	m_rightIndent = indent;
}

int RowFormat::getFirstRowIndent()
{
	return m_firstRowIndent;
}
void RowFormat::setFirstRowIndent(int indent)
{
	m_firstRowIndent = indent;
}

int RowFormat::getRowSpace()
{
	return m_rowSpace;
}

void RowFormat::setRowSpace(int space)
{
	m_rowSpace = space;
}

int RowFormat::getWordSpace()
{
	return m_wordSpace;
}

void RowFormat::setWordSpace(int space)
{
	m_wordSpace = space;
}