#ifndef _FZCONTROLLER_H_
#define _fZCONTROLLER_H_

#include "stdafx.h"
#include "Graphics.h"
#include "FzDoc.h"
#include "FzView.h"

#define MAX_LOADSTRING 100

class FzController
{
private:
	FzController();

public:
	~FzController();

	//singleleton
	static FzController *getInstance();

	void init();

	LRESULT CALLBACK FzController::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	ATOM FzController::registerClass();
	void update();

private:
	static FzController *m_instance;

	TCHAR m_szWindowClass[MAX_LOADSTRING], m_szTitle[MAX_LOADSTRING];

	HWND m_hWnd;
	Graphics *m_g;
	FzDoc *m_doc;
	FzView *m_view;

};

#endif