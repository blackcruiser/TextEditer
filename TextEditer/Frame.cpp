#include "stdafx.h"
#include "Resource.h"
#include "Frame.h"
#include "SimpleCompositor.h"

Frame* Frame::m_instance = NULL;

LRESULT CALLBACK windowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return Frame::getInstance()->wndProc(hWnd, message, wParam, lParam);
}


Frame::Frame()
{
}

Frame::~Frame()
{
	delete m_docment;
	delete m_g;
}

void Frame::init()
{
	LoadString((HINSTANCE)GetModuleHandle(0), IDS_APP_TITLE, m_szTitle, MAX_LOADSTRING);
	LoadString((HINSTANCE)GetModuleHandle(0), IDS_APP_TITLE, m_szWindowClass, MAX_LOADSTRING);

	registerClass();
	m_hWnd = CreateWindow(m_szWindowClass, m_szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, (HINSTANCE)GetModuleHandle(0), NULL);
	if (!m_hWnd)
		throw _T("Frame : m_hWnd == NULL");

	m_g = new Graphics();
	m_g->setDc(GetDC(m_hWnd));

	m_docment = DocumentGlyph::createEmptyDoc();
	m_docment->setCompositor(new SimpleCompositor());
	m_view = m_docment->compose(m_g);

	ShowWindow(m_hWnd, SW_SHOWNORMAL);
	UpdateWindow(m_hWnd);
}

Frame *Frame::getInstance()
{
	if (m_instance == NULL)
		m_instance = new Frame();

	return m_instance;
}

ATOM Frame::registerClass()
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

LRESULT Frame::wndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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

void Frame::update()
{
	PAINTSTRUCT ps;
	HDC hdc;

	hdc = BeginPaint(m_hWnd, &ps);
	// TODO: 在此添加任意绘图代码...
	m_g->setDc(hdc);
	m_view->draw(m_g, 10, 10); 

	EndPaint(m_hWnd, &ps);
}
