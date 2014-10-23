#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include "stdafx.h"

class Graphics
{
public:
	Graphics();
	~Graphics();

	void setDc(HDC hDc);

	void moveTo(int x, int y);
	void getCurPox(int &x, int &y);

	void drawText();

private:
	HDC m_hDc;
	int m_x, m_y;
};

#endif