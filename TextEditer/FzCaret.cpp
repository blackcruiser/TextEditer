#include "stdafx.h"
#include "FzCaret.h"

FzCaret::FzCaret()
{
}

FzCaret::~FzCaret()
{
}

void FzCaret::setLogicDoc(BaseGlyph *doc)
{
	m_logicDoc = doc;
}

void FzCaret::setPhysicDoc(BaseGlyph *doc)
{
	m_physicDoc = doc;
}

void FzCaret::setLoc(int x, int y)
{
	BaseIterator *pageIter, *rowIter, *charIter;
	BaseGlyph *page, *row, *character;
	FzRect rect;
	bool isFind;

	pageIter = m_logicDoc->createIterator();
	isFind = false;
	for (pageIter->init(); !pageIter->isEnd(); pageIter->next())
	{
		page = pageIter->getValue();
		page->getLoc(rect);

		if (rect.y <= y && y <= rect.y + rect.height - 1)
		{
			isFind = true;
			break;
		}
	}

	if (!isFind)
	{
		if (y > rect.y + rect.height - 1)
			page = m_logicDoc->getChild(-1);
		else
			page = m_logicDoc->getChild(0);
	}

	rowIter = page->createIterator();
	isFind = false;
	for (rowIter->init(); !rowIter->isEnd(); rowIter->next())
	{
		row = rowIter->getValue();
		row->getLoc(rect);

		if (rect.y <= y && y <= rect.y + rect.height - 1)
		{
			isFind = true;
			break;
		}
	}

	if (!isFind)
	{
		if (y > rect.y + rect.height - 1)
			row = page->getChild(-1);
		else
			row = page->getChild(0);
	}

	charIter = row->createIterator();
	isFind = false;
	for (charIter->init(); !charIter->isEnd(); charIter->next())
	{
		character = charIter->getValue();
		character->getLoc(rect);

		if (rect.x <= x && x <= rect.x + rect.width - 1)
		{
			isFind = true;
			break;
		}
	}

	if (!isFind)
	{
		if ( x > rect.x + rect.width - 1)
			character = row->getChild(-1);
		else
			character = row->getChild(0);
	}
	m_page = page;
	m_row = row;
	m_character = character;

	m_paragraph = character->getParent();


	character->getLoc(rect);
	m_x = rect.x + rect.width - 1 + 1;
	m_y = rect.y;
	m_height = rect.height;
}

void FzCaret::draw(Graphics *g)
{
	g->SetCaretPos(m_x, m_y);
}