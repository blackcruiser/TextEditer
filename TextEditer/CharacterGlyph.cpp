#include "stdafx.h"
#include "CharacterGlyph.h"

CharacterGlyph::CharacterGlyph(BaseGlyph *parent):
	BaseGlyph(parent), m_text(_T('Îª')), m_font(0), m_size(20)
{
	RECT rect;

	
	DrawText(hdc, text, -1, &rect, DT_CALCRECT);
	m_boundBox = 
}


CharacterGlyph::~CharacterGlyph()
{

}


void CharacterGlyph::draw(HDC hdc, Rect boundBox)
{
	HFONT hFont;
	TCHAR *text;
	RECT rect;

	hFont = CreateFont(m_size, 0, 0, 0, 0, FALSE, FALSE, FALSE, 
		ANSI_CHARSET, 
		OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS, 
		DEFAULT_QUALITY, 
		DEFAULT_PITCH | FF_SWISS, 
		_T("Ó×Ô²"));

	text[0] = m_text;
	text[0] = _T('\0');

	rect.left = boundBox.x;
	rect.right = boundBox.x + boundBox.width - 1;
	rect.top = boundBox.y;
	rect.bottom= boundBox.y + boundBox.height - 1;


	SelectObject(hdc, hFont);

	DrawText(hdc, text, -1, &rect, DT_CALCRECT);
	DrawText(hdc, text, -1, &rect, DT_LEFT | DT_TOP | DT_WORDBREAK);

	DeleteObject(hFont);
}