#include "stdafx.h"
#include "ParagraphGlyph.h"

ParagraphGlyph::ParagraphGlyph(BaseGlyph *parent) :
	BaseGlyph(parent)
{

}

ParagraphGlyph::~ParagraphGlyph()
{

}

void ParagraphGlyph::format(int start, int end, FzFont font, FzSize size, FzStyle startyle)
{
	std::list<CharacterFormat *>::iterator iter, iterSt, iterEd;
	int start0, end0, start1, end1, formatSt, formatEd;

	start0 = start;
	end0 = start- 1;
	start1 = end + 1;
	end1 = end;
	for (iter = m_formatList.begin(); iter != m_formatList.end(); iter++)
	{
		formatSt= (*iter)->getStart();
		formatEd = (*iter)->getEnd();

		if (formatEd < start)
			break;

		if (start<= formatSt && end <= formatEd)
		{
			iterSt = iter;
			end0 = formatSt - 1;

			break;
		}
	}

	//处理头边�?
	if (start0 <= end0 && iterSt != m_formatList.begin())
	{
		(*iterSt)--;
		CharacterFormat *newFormat = new CharacterFormat((*iterSt)->getStart(), start0 - 1, (*iterSt)->getFont(), (*iterSt)->getSize(), (*iter)->getStyle());
		m_formatList.insert(iterSt, newFormat);

		(*iterSt)->setStart(start0);
		(*iterSt)->setFont(font);
		(*iterSt)->setSize(size);
		(*iterSt)->setStyle(startyle);
	}

	for (iter = m_formatList.end(), iter--; iter != m_formatList.begin(); iter--)
	{
		formatSt= (*iter)->getStart();
		formatEd = (*iter)->getEnd();

		if (formatEd < start)
			break;

		if (start <= formatSt && end <= formatEd)
		{
			iterEd= iter;
			start1 = formatEd + 1;

			break;
		}

		if (iter == m_formatList.begin() && formatSt> end)
			break;
	}

	//如果存在startart和end跨越了多个现有的foramt
	if (start0 <= end0 && start1 <= end1)
	{
		iterEd++;
		for (iter = iterSt, iter++; iter != iterEd; iter = m_formatList.erase(iter));

		CharacterFormat *newFormat = new CharacterFormat(end0 + 1, start1 - 1, font, size, startyle);
		m_formatList.insert(iterEd, newFormat);
	}

	//处理尾边�?
	if (start1 <= end1 && iterEd != m_formatList.begin())
	{
		CharacterFormat *newFormat = new CharacterFormat(end1 + 1, (*iterEd)->getEnd(), font, size, startyle);
		m_formatList.insert(iterEd, newFormat);

		(*iterEd)->setStart(end1 + 1);
	}
}
