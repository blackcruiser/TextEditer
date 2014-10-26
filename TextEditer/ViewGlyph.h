#ifndef _VIEWGLYPH_H_
#define _VIEWGLYPH_H_

#include "stdafx.h"
#include "BaseGlyph.h"

class ViewGlyph : public BaseGlyph
{
public:
	ViewGlyph(BaseGlyph *parent);
	ViewGlyph();
	~ViewGlyph();

	virtual void draw(Graphics *g, int x, int y);

private:
};

#endif;