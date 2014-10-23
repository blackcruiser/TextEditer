#ifndef _CHARACTERFORMAT_H_
#define _CHARACTERFORMAT_H_

#include "stdafx.h"
#include "FzFont.h"
#include "FzSize.h"
#include "FzStyle.h"

class CharacterFormat 
{
public:
	CharacterFormat(int start, int end, FzFont font, FzSize size, FzStyle style);
	~CharacterFormat();

	int getStart();
	int getEnd();
	void setStart(int start);
	void setEnd(int end);

	void setFont(FzFont font);
	FzFont getFont();
	void setSize(FzSize size);
	FzSize getSize();
	void setStyle(FzStyle style);
	FzStyle getStyle();

private:
	int m_start, m_end;

	FzFont m_font;
	FzSize m_size;
	FzStyle m_style;
};

#endif