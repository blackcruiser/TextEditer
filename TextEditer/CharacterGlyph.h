#ifndef _CHARACTERGLYPH_H_
#define _CHARACTERGLYPH_H_

#include "stdafx.h"

#include "BaseGlyph.h"

class CharacterGlyph : public BaseGlyph
{
public:
	CharacterGlyph(BaseGlyph *parent);
	virtual ~CharacterGlyph();

	virtual void draw(HDC hdc, Rect boundBox);

private:
	TCHAR m_text;
	int m_font;
	int m_size;

};
	
#endif
