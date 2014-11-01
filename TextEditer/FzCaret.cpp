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
	FzRect pageRect, rowRect, charRect;
	bool isFind;

	pageIter = m_logicDoc->createIterator();
	isFind = false;
	for (pageIter->init(); !pageIter->isEnd(); pageIter->next())
	{
		page = pageIter->getValue();
		page->getLoc(pageRect);

		if (pageRect.y <= y && y <= pageRect.y + pageRect.height - 1)
		{
			isFind = true;
			break;
		}
	}

	if (!isFind)
	{
		if (y > pageRect.y + pageRect.height - 1)
			page = m_logicDoc->getChild(-1);
		else
			page = m_logicDoc->getChild(0);

		page->getLoc(pageRect);
	}

	rowIter = page->createIterator();
	isFind = false;
	for (rowIter->init(); !rowIter->isEnd(); rowIter->next())
	{
		row = rowIter->getValue();
		row->getLoc(rowRect);
		rowRect.x += pageRect.x;
		rowRect.y += pageRect.y;

		if (rowRect.y <= y && y <= rowRect.y + rowRect.height - 1)
		{
			isFind = true;
			break;
		}
	}

	if (!isFind)
	{
		if (y > rowRect.y + rowRect.height - 1)
			row = page->getChild(-1);
		else
			row = page->getChild(0);

		row->getLoc(rowRect);
		rowRect.x += pageRect.x;
		rowRect.y += pageRect.y;
	}

	charIter = row->createIterator();
	isFind = false;
	for (charIter->init(); !charIter->isEnd(); charIter->next())
	{
		character = charIter->getValue();
		character->getLoc(charRect);
		charRect.x += rowRect.x;
		charRect.y += rowRect.y;

		if (charRect.x <= x && x <= charRect.x + charRect.width - 1)
		{
			isFind = true;
			break;
		}
	}

	if (!isFind)
	{
		if ( x > charRect.x + charRect.width - 1)
			character = row->getChild(-1);
		else
			character = row->getChild(0);
	}
	m_page = page;
	m_row = row;
	m_character = character;

	m_paragraph = character->getParent();


	character->getLoc(charRect);
	charRect.x += rowRect.x;
	charRect.y += rowRect.y;
	m_x = charRect.x + charRect.width - 1 + 1;
	m_y = charRect.y;
	m_height = charRect.height;
}

void FzCaret::draw(Graphics *g)
{
	g->createCaret(0, m_height);
	g->setCaretPos(m_x, m_y);
	g->showCaret();
}