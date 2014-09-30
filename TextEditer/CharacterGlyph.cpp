#include "stdafx.h"
#include "CharacterGlyph.h"

CharacterGlyph::CharacterGlyph(BaseGlyph *_parent):
	BaseGlyph(_parent)
{
	text = _T("Ϊ���� ��į�� ����������һ��");

}


CharacterGlyph::~CharacterGlyph()
{

}


void CharacterGlyph::draw(HDC hdc)
{
	RECT rect = {10, 10, 0, 0};

	DrawText(hdc, text, -1, &rect, DT_CALCRECT);
	DrawText(hdc, text, -1, &rect, DT_LEFT|DT_TOP|DT_WORDBREAK);
}