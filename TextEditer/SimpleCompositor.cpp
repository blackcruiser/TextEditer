#include "stdafx.h"
#include "fzUtil.h"
#include "SimpleCompositor.h"
#include "BaseIterator.h"
#include "RowGlyph.h"
#include "PageGlyph.h"
#include "ParagraphGlyph.h"
#include "DocumentGlyph.h"
#include "ViewGlyph.h"
#include "RowFormat.h"
#include "PageFormat.h"

BaseGlyph *SimpleCompositor::compose(Graphics *g, BaseGlyph *document)
{
	ViewGlyph *view;
	std::list<BaseGlyph *> pageList;
	FzRect rect0, rect1;

	createPage(g, document, pageList);

	rect0.x = rect0.y = 0;
	view = new ViewGlyph();
	for (std::list<BaseGlyph *>::iterator pageIter = pageList.begin(); pageIter != pageList.end(); pageIter++)
	{
		(*pageIter)->getBound(g, rect1);
		rect0.width = rect1.width;
		rect0.height = rect1.height;

		view->addChild(*pageIter, -1);
		(*pageIter)->setParent(view);
		(*pageIter)->setLoc(rect0);
		rect0.height += rect1.height + 10;
	}

	return view;

}

void SimpleCompositor::createPage(Graphics *g, BaseGlyph *document, std::list<BaseGlyph *> &pageList)
{
	BaseIterator *iter;
	PageFormat *pageFormat;
	PageGlyph *page;
	std::list<BaseGlyph *> rowList;
	FzRect rect, locRect;
	int height ,pageHeight;

	pageFormat = dynamic_cast<DocumentGlyph *>(document)->getPageFormat();
	pageHeight = pageFormat->getHeight() - pageFormat->getTopMargin() - pageFormat->getBottomMargin();

	iter = document->createIterator();
	for (iter->init(); !iter->isEnd(); iter->next())
		createRow(g, iter->getValue(), rowList);

	height = 0;
	page = new PageGlyph();
	locRect.x = pageFormat->getLeftMargin();
	locRect.y = pageFormat->getTopMargin();
	for (std::list<BaseGlyph *>::iterator rowIter = rowList.begin(); rowIter != rowList.end(); rowIter++)
	{
		(*rowIter)->getBound(g, rect);
		height += rect.height;

		if (height > pageHeight)
		{
			
			page->setFormat(pageFormat);
			pageList.push_back(page);

			page = new PageGlyph();
			height = 0;
			locRect.y = pageFormat->getTopMargin();
		}

		locRect.width = rect.width;
		locRect.height = rect.height;

		page->addChild(*rowIter, -1);
		(*rowIter)->setParent(page);
		(*rowIter)->setLoc(locRect);

		locRect.y += rect.height;
	}

	page->setFormat(pageFormat);
	pageList.push_back(page);
	
	delete iter;
}

void SimpleCompositor::createRow(Graphics *g, BaseGlyph *paragraph, std::list<BaseGlyph *> &rowList)
{
	BaseIterator *iter;
	BaseGlyph *charGlyph;
	RowFormat *rowFormat;
	RowGlyph *row;
	FzRect rect, locRect;
	int width, maxHeight, rowWidth;

	width = maxHeight = 0;
	iter = paragraph->createIterator();
	rowFormat =	dynamic_cast<ParagraphGlyph *>(paragraph)->getRowFormat();
	row = new RowGlyph();
	rowWidth = rowFormat->getWidth() - rowFormat->getLeftIndent() - rowFormat->getRightIndent();

	locRect.x = rowFormat->getLeftIndent();
	locRect.y = rowFormat->getRowSpace();
	for (iter->init(); !iter->isEnd(); iter->next())
	{
		charGlyph = iter->getValue();
		charGlyph->getBound(g, rect);
		width += rect.width;

		if (width <= rowWidth)
		{
			if (rect.height > maxHeight)
				maxHeight = rect.height;
		}
		else
		{
			row->setFormat(rowFormat);
			row->setHeight(maxHeight);
			rowList.push_back(row);

			row = new RowGlyph();
			width = rect.width;
			maxHeight = 0;
			locRect.x = rowFormat->getLeftIndent();
		}
		locRect.width = rect.width;
		locRect.height = rect.height;
		row->addChild(charGlyph, -1);
		charGlyph->setParent(row);
		charGlyph->setLoc(locRect);

		locRect.x += rect.width + rowFormat->getWordSpace();
	}

	row->setFormat(rowFormat);
	row->setHeight(maxHeight);
	rowList.push_back(row);

	delete iter;
}