#ifndef _CHARACTERGLYPH_H_
#define _CHARACTERGLYPH_H_

#include "stdafx.h"
#include "BaseGlyph.h"
#include "FzFont.h"
#include "FzSize.h"
#include "FzStyle.h"

class CharacterGlyph : public BaseGlyph
{
public:
	CharacterGlyph(BaseGlyph *parent);
	CharacterGlyph(TCHAR c, FzFont *font, FzSize *size, FzStyle *style);
	CharacterGlyph();
	virtual ~CharacterGlyph();

	virtual void getBound(Graphics *g, FzRect &rect);
	virtual void draw(Graphics *g, int x, int y);

private:
	TCHAR m_c;
	FzFont *m_font;
	FzSize *m_size;
	FzStyle *m_style;
};
	
#endif