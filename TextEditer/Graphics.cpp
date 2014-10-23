#include "stdafx.h"
#include "Graphics.h"

Graphics::Graphics()
{

}

Graphics::~Graphics()
{
}

void Graphics::setDc(HDC hDc)
{
	m_hDc = hDc;
}

void Graphics::moveTo(int x, int y)
{
	m_x = x;
	m_y = y;
}

void Graphics::getCurPox(int &x, int &y)
{
	x = m_x;
	y = m_y;
}

