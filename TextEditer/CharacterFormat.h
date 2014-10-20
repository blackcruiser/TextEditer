#ifndef _CHARACTERFORMAT_H_
#define _CHARACTERFORMAT_H_

#include "stdafx.h"

class CharacterFormat 
{
public:
	CharacterFormat();
	~CharacterFormat();

	int getStart();
	int getEnd();
	int setStart(int start);
	int setEnd(int end);

	void setFont(fzFont font);
	fzFont getFont();
	void setSize(fzSize size);
	fzSize getFont();
	void setStyle(fzStyle style);
	fzStyle getFont();

private:
	int m_start, m_end;

	fzFont m_font;
	fzSize m_size;
	fzStyle m_style;
};

#endif