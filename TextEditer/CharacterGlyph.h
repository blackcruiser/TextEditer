#ifndef _CHARACTERGLYPH_H_
#define _CHARACTERGLYPH_H_

#include "stdafx.h"
#include "BaseGlyph.h"

class CharacterGlyph : public BaseGlyph
{
public:
	CharacterGlyph(BaseGlyph *parent);
	virtual ~CharacterGlyph();

	virtual void draw(Graphics *g);

private:
	TCHAR m_c;
};
	
#endif