#include "stdafx.h"
#include "FzView.h"
#include "FzColor.h"


FzView::FzView(FzDoc *doc, Graphics *g):
m_x(0), m_y(0), m_deltaX(0), m_deltaY(0)
{
	m_g = g;
	m_g->getClientRect(m_clientRect);

	m_doc = doc;
	m_docContext = m_doc->getContext(m_g);

	m_caret = new FzCaret();
	m_caret->setLogicDoc(m_docContext);
	m_caret->setLoc(0, 0);
	m_caret->draw(m_g);
}


FzView::~FzView()
{
}


void FzView::update()
{
	m_docContext = m_doc->getContext(m_g);
}

void FzView::draw()
{
	m_g->drawRect(&m_clientRect, &m_bkgColor);
	m_docContext->draw(m_g, m_x, m_y);
}