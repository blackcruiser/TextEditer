#include "stdafx.h"
#include "PageFormat.h"

PageFormat::PageFormat()
{

}

PageFormat::PageFormat(int leftMargin, int rightMargin, int topMargin, int bottomMargin, int width, int height) :
m_leftMargin(leftMargin), m_rightMargin(rightMargin), m_topMargin(topMargin), m_bottomMargin(bottomMargin), m_width(width), m_height(height)
{
}

PageFormat::~PageFormat()
{

}

void PageFormat::setWidth(int width)
{
	m_width = width;
}

int PageFormat::getWidth()
{
	return m_width;
}

void PageFormat::setHeight(int height)
{
	m_height = height;
}

int PageFormat::getHeight()
{
	return m_height;
}

void PageFormat::setLeftMargin(int margin)
{
	m_leftMargin = margin;
}

int PageFormat::getLeftMargin()
{
	return m_leftMargin;
}

void PageFormat::setRightMargin(int margin)
{
	m_rightMargin = margin;
}

int PageFormat::getRightMargin()
{
	return m_rightMargin;
}

void PageFormat::setTopMargin(int margin)
{
	m_topMargin = margin;
}

int PageFormat::getTopMargin()
{
	return m_topMargin;
}

void PageFormat::setBottomMargin(int margin)
{
	m_bottomMargin = margin;
}

int PageFormat::getBottomMargin()
{
	return m_bottomMargin;
}