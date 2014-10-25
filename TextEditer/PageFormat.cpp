#include "PageFormat.h"

PageFormat::PageFormat()
{

}

PageFormat::~PageFormat()
{

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