#ifndef _FZDOC_H_
#define _FZDOC_H_

#include "stdafx.h"
#include "Graphics.h"
#include "DocumentGlyph.h"
#include "FzCaret.h"

class FzView;

class FzDoc
{
public:
	FzDoc();
	~FzDoc();

	void attach(FzView *view);
	void detach(FzView *view);
	void notify();

	BaseGlyph *getContext(Graphics *g);

private:
	DocumentGlyph *m_document;
	FzCaret *m_caret;
	std::list<FzView *> m_viewList;
};

#endif
