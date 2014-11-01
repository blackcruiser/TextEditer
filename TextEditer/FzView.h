#ifndef _FZVIEW_H_
#define _FZVIEW_H_

#include "stdafx.h"
#include "Graphics.h"
#include "FzDoc.h"

class FzView
{
public:
	FzView(FzDoc *doc, Graphics *g);
	~FzView();

	void update();
	void draw();

private:
	Graphics *m_g;
	FzDoc *m_doc;
	BaseGlyph *m_docContext;
	FzCaret *m_caret;
	//x,y: where to draw; deltaX,deltaY: location relevent to page
	int m_x, m_y, m_deltaX, m_deltaY;
	FzRect m_clientRect;
	FzColor m_bkgColor;
};

#endif
