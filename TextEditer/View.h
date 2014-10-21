#ifndef _VIEW_H_
#define _VIEW_H_

#include "stdafx.h"
#include "Graphics.h"
#include "DocumentGlyph.h"

class View
{
public:
	View();
	~View();

	void draw(Graphics *g);

private:
	DocumentGlyph *m_document;

};

#endif