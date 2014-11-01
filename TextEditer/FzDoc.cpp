#include "stdafx.h"
#include "FzDoc.h"
#include "FzView.h"

FzDoc::FzDoc()
{
	m_document = DocumentGlyph::createEmptyDoc();
}


FzDoc::~FzDoc()
{
}

void FzDoc::attach(FzView *view)
{
	m_viewList.push_back(view);
}

void FzDoc::detach(FzView *view)
{
	m_viewList.remove(view);
}

void FzDoc::notify()
{
	std::list<FzView *>::iterator iter;

	for (iter = m_viewList.begin(); iter != m_viewList.end(); iter++)
		(*iter)->update();
}

BaseGlyph *FzDoc::getContext(Graphics *g)
{
	return m_document->compose(g);
}