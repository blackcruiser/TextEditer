#include "stdafx.h"
#include "CharacterGlyph.h"

CharacterGlyph::CharacterGlyph(BaseGlyph *parent):
	BaseGlyph(parent), text(_T("Ϊ���� ��į�� ����������һ��")), font(0), size(20)
{
}


CharacterGlyph::~CharacterGlyph()
{

}


void CharacterGlyph::draw(HDC hdc)
{
	RECT rect = {0, 0, 0, 0};
	HFONT hFont;

	hFont = CreateFont(size, 0, 0, 0, 0, FALSE, FALSE, FALSE, 
		ANSI_CHARSET, 
		OUT_DEFAULT_PRECIS, 
		CLIP_DEFAULT_PRECIS, 
		DEFAULT_QUALITY, 
		DEFAULT_PITCH | FF_SWISS, 
		_T("��Բ"));

	SelectObject(hdc, hFont);

	DrawText(hdc, text, -1, &rect, DT_CALCRECT);
	DrawText(hdc, text, -1, &rect, DT_LEFT | DT_TOP | DT_WORDBREAK);

	DeleteObject(hFont);
}