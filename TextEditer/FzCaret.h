#ifndef _FZCARET_H_
#define _FZCARET_H_

#include "stdafx.h"
#include "Graphics.h"
#include "BaseGlyph.h"

class FzCaret
{
public:
	FzCaret();
	~FzCaret();

	void setLoc(int x, int y);
	void getPhysicLoc();

	void setLogicDoc(BaseGlyph *doc);

	void draw(Graphics *g);

private:
	int m_height, m_x, m_y;
	BaseGlyph *m_logicDoc, *m_page, *m_row, *m_character, *m_paragraph;


};

#endif