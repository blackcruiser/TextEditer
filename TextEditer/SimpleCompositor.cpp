#include "stdafx.h"
#include "SimpleCompositor.h"
#include "BaseIterator.h"

BaseGlyph *SimpleCompositor::compose(Graphics *g, DocumentGlyph *document)
{
	createPage(g, document);
}

void SimpleCompositor::createPage(Graphics *g, DocumentGlyph *document)
{
	BaseIterator *iter;

	iter = document->createIterator();
	for (iter->init(); iter->isEnd(); iter->next())
	{

	}

	delete iter;
}

void SimpleCompositor::createRow(Graphics *g, std::list<BaseGlyph *>::iterator iter)
{

}