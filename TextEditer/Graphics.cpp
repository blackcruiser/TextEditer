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

void Graphics::getClientRect(FzRect &rect)
{
	RECT wRect;

	GetClientRect(m_hWnd, &wRect);

	rect.x = wRect.left;
	rect.y = wRect.top;
	rect.width = wRect.right - wRect.left + 1;
	rect.height = wRect.bottom - wRect.top + 1;
}

void Graphics::createCaret(int width, int height)
{
	CreateCaret(m_hWnd, NULL, width, height);
}

void Graphics::setCaretPos(int x, int y)
{
	SetCaretPos(x, y);
}

void Graphics::showCaret()
{
	ShowCaret(m_hWnd);
}

void Graphics::drawRect(FzRect *rect, FzColor *color)
{
	RECT wRect;
	HBRUSH brush;
	COLORREF wColor;

	wRect.left = rect->x;
	wRect.top = rect->y;
	wRect.right = rect->x + rect->width - 1;
	wRect.bottom = rect->y + rect->height - 1;

	wColor = RGB(50, 50, 50);
	brush = CreateSolidBrush(wColor);
	FillRect(m_hDc, &wRect, brush);
}

void Graphics::drawText(int x, int y, TCHAR *szBuffer, int len, FzFont *font, FzSize *size, FzStyle *style)
{
	HFONT temp, hFont;

	hFont = CreateFont(size->height, 0, 0, 0, 0, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("ËÎÌå"));
	temp = (HFONT)SelectObject(m_hDc, hFont);

	TextOut(m_hDc, x, y, szBuffer, len);

	SelectObject(m_hDc, temp);
	DeleteObject(hFont);
}

void Graphics::getTextBound(TCHAR *szBuffer, int len, FzFont *font, FzSize *size, FzStyle *style, FzRect &rect)
{
	RECT wRect = { 0, 0, 0, 0 };
	HFONT temp, hFont;

	hFont = CreateFont(size->height, 0, 0, 0, 0, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, _T("Î¢ÈíÑÅºÚ"));
	int c = GetLastError();
	temp = (HFONT)SelectObject(m_hDc, hFont);


	DrawText(m_hDc, szBuffer, len, &wRect, DT_CENTER | DT_CALCRECT);

	SelectObject(m_hDc, temp);
	DeleteObject(hFont);

	rect.width = wRect.right - wRect.left + 1;
	rect.height = wRect.bottom - wRect.top + 1;
}

