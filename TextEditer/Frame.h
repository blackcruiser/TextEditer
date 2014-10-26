#ifndef _FRAME_H_
#define _FRAME_H_

#include "stdafx.h"
#include "DocumentGlyph.h"
#include "Graphics.h"

#define MAX_LOADSTRING 100

class Frame
{
private:
	Frame();

public:
	~Frame();

	//singleleton
	static Frame *getInstance();

	void init();

	LRESULT CALLBACK Frame::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	ATOM Frame::registerClass();
	void update();

private:
	static Frame *m_instance;

	TCHAR m_szWindowClass[MAX_LOADSTRING], m_szTitle[MAX_LOADSTRING];

	HWND m_hWnd;
	DocumentGlyph *m_docment;
	BaseGlyph *m_view;
	Graphics *m_g;

};

#endif