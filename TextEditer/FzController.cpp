#include "stdafx.h"
#include "Resource.h"
#include "FzController.h"
#include "SimpleCompositor.h"

FzController* FzController::m_instance = NULL;

LRESULT CALLBACK windowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return FzController::getInstance()->wndProc(hWnd, message, wParam, lParam);
}


FzController::FzController()
{
}

FzController::~FzController()
{
	delete m_doc;
	delete m_view;
	delete m_g;
}

void FzController::init()
{
	LoadString((HINSTANCE)GetModuleHandle(0), IDS_APP_TITLE, m_szTitle, MAX_LOADSTRING);
	LoadString((HINSTANCE)GetModuleHandle(0), IDS_APP_TITLE, m_szWindowClass, MAX_LOADSTRING);

	registerClass();
	m_hWnd = CreateWindow(m_szWindowClass, m_szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, (HINSTANCE)GetModuleHandle(0), NULL);
	if (!m_hWnd)
		throw _T("FzController : m_hWnd == NULL");

	int c = GetLastError();
	m_g = new Graphics();
	m_g->setWnd(m_hWnd);

	m_doc = new FzDoc();
	m_view = new FzView(m_doc, m_g);
	m_doc->attach(m_view);

	ShowWindow(m_hWnd, SW_SHOWNORMAL);
	UpdateWindow(m_hWnd);
}

FzController *FzController::getInstance()
{
	if (m_instance == NULL)
		m_instance = new FzController();

	return m_instance;
}

ATOM FzController::registerClass()
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = windowProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = (HINSTANCE)GetModuleHandle(0);
	wcex.hIcon = LoadIcon((HINSTANCE)GetModuleHandle(0), MAKEINTRESOURCE(IDI_TEXTEDITER));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_TEXTEDITER);
	wcex.lpszClassName = m_szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

LRESULT FzController::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 分析菜单选择:
		switch (wmId)
		{
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
	{
		update();
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void FzController::update()
{
	PAINTSTRUCT ps;
	HDC hdc;

	hdc = BeginPaint(m_hWnd, &ps);
	// TODO: 在此添加任意绘图代码...
	m_view->draw(); 

	EndPaint(m_hWnd, &ps);
}
