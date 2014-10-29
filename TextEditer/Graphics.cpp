#include "stdafx.h"
#include "Graphics.h"

Graphics::Graphics() :
m_hDc(NULL)
{

}

Graphics::~Graphics()
{
}

void Graphics::setWnd(HWND hWnd)
{
	m_hWnd = hWnd;
	m_hDc = GetDC(m_hWnd);
}

void Graphics::createCaret(int width, int height)
{
	CreateCaret(m_hWnd, NULL, width, height);
}

void Graphics::setCaretPos(int x, int y)
{
	SetCaretPos(x, y);
}

void Graphics::drawText(int x, int y, TCHAR *szBuffer, int len, FzFont *font, FzSize *size, FzStyle *style)
{
	HFONT temp, hFont;

	hFont = CreateFont(size->height, 0, 0, 0, 0, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("ËÎÌו"));
	temp = (HFONT)SelectObject(m_hDc, hFont);

	TextOut(m_hDc, x, y, szBuffer, len);

	SelectObject(m_hDc, temp);
	DeleteObject(hFont);
}

void Graphics::getTextBound(TCHAR *szBuffer, int len, FzFont *font, FzSize *size, FzStyle *style, FzRect &rect)
{
	RECT wRect = { 0, 0, 0, 0 };
	HFONT temp, hFont;

	hFont = CreateFont(size->height, 0, 0, 0, 0, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("ËÎÌו"));
	temp = (HFONT)SelectObject(m_hDc, hFont);

	DrawText(m_hDc, szBuffer, len, &wRect, DT_CENTER | DT_CALCRECT);

	SelectObject(m_hDc, temp);
	DeleteObject(hFont);

	rect.width = wRect.right - wRect.left + 1;
	rect.height = wRect.bottom - wRect.top + 1;
}

