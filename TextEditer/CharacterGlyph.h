#ifndef _CHARACTERGLYPH_H_
#define _CHARACTERGLYPH_H_

#include "stdafx.h"

#include "BaseGlyph.h"

class CharacterGlyph : public BaseGlyph
{
public:
	CharacterGlyph(BaseGlyph *parent);
	~CharacterGlyph();

	virtual void draw(HDC hdc);

private:
	LPTSTR text;
	int font;
	int size;

};
	
#endif
