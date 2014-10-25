#ifndef _PAGEFORMAT_H_
#define _PAGEFORMAT_H_

#include "stdafx.h"

class PageFormat
{
public:
	PageFormat();
	~PageFormat();

	void setLeftMargin(int margin);
	int getLeftMargin();
	void setRightMargin(int margin);
	int getRightMargin();
	void setTopMargin(int margin);
	int getTopMargin();
	void setBottomMargin(int margin);
	int getBottomMargin();

private:
	int m_leftMargin, m_rightMargin, m_topMargin, m_bottomMargin;
};

#endif