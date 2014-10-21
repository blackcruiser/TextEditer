#ifndef _FRAME_H_
#define _FRAME_H_

#include "stdafx.h"
#include "View.h"
#include "Graphics.h"

#define MAX_LOADSTRING 100

class Frame
{
private:
	Frame();

public:
	~Frame();

	//singleletonģʽ
	static Frame *getInstance();

	LRESULT CALLBACK Frame::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	ATOM Frame::registerClass(HINSTANCE hInstance);
	void update();

private:
	static Frame *m_instance;

	TCHAR m_szWindowClass[MAX_LOADSTRING], m_szTitle[MAX_LOADSTRING];

	HWND m_hWnd;
	View *m_view;
	Graphics *m_g;

};

#endif