#ifndef _GRAPHICS_H_
#define _GRAPYICS_H_

#include "stdafx.h"

class Graphics
{
public:
	Graphics();
	~Graphics();

	void setDc(HDC hDc);
	void drawText();

private:
	HDC m_hDc;
};

#endif