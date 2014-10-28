#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "stdafx.h"
#include "fzUtil.h"
#include "FzFont.h"
#include "FzSize.h"
#include "FzStyle.h"

class Graphics
{
public:
	Graphics();
	~Graphics();

	void setDc(HDC hDc);

	void createCaret();
	void setCaretPos(int x, int y);
	void drawText(int x, int y, TCHAR *szBuffer, int len, FzFont *font, FzSize *size, FzStyle *style);
	void getTextBound(TCHAR *szBuffer, int len, FzFont *font, FzSize *size, FzStyle *style, FzRect &rect);

private:
	HDC m_hDc;
	HWND m_hWnd;
	int m_x, m_y, m_width, m_height;
};

#endif