#include "stdafx.h"
#include "CharacterGlyph.h"

CharacterGlyph::CharacterGlyph(BaseGlyph *parent):
	BaseGlyph(parent), m_text(_T("为何让 寂寞长 我在世界这一边")), m_font(0), m_size(20)
{
}


CharacterGlyph::~CharacterGlyph()
{

}


void CharacterGlyph::draw(HDC hdc)
{
	RECT rect = {0, 0, 0, 0};
	HFONT hFont;

	hFont = CreateFont(m_size, 0, 0, 0, 0, FALSE, FALSE, FALSE, 
		ANSI_CHARSET, 
		OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS, 
		DEFAULT_QUALITY, 
		DEFAULT_PITCH | FF_SWISS, 
		_T("幼圆"));

	SelectObject(hdc, hFont);

	DrawText(hdc, m_text, -1, &rect, DT_CALCRECT);
	DrawText(hdc, m_text, -1, &rect, DT_LEFT | DT_TOP | DT_WORDBREAK);

	DeleteObject(hFont);
}