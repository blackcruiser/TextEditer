#include "ParagraphGlyph.h"

ParagraphGlyph::ParagraphGlyph(BaseGlyph *parent) :
	BaseGlyph(parent)
{

}

ParagraphGlyph::~ParagraphGlyph()
{

}

void ParagraphGlyph::format(int start, int end, fzFont font, fzSize size, fzStyle style)
{
	std::list<CharacterFormat *>::iterator iter, iterSt, iterEd;
	int st0, ed0, st1, ed1, formatSt, formatEd;

	st0 = start;
	ed0 = start - 1;
	st1 = end + 1;
	ed1 = end;
	for (iter = m_formatList.begin(); iter != m_formatList.end(); iter++)
	{
		formatSt = iter->getStart();
		formatEd = iter->getEnd();

		if (formatEd < st)
			break;

		if (st <= formatSt && ed <= formatEd)
		{
			iterSt = iter;
			ed0 = formatSt - 1;

			break;
		}
	}

	//处理头边界
	if (st0 <= ed0 && iterSt != m_formatList.begin())
	{
		iterSt--;
		CharacterFormat *newFormat = new CharacterFormat(iterSt->getStart(), st0 - 1, iterSt->getFont(), iterSt->getSize(), iter->getStyle());
		m_formatList.insert(iterSt, newFormat);

		iterSt->setStart(st0);
		iterSt->setFont(font);
		iterSt->setSize(size);
		iterSt->setStyle(style);
	}

	for (iter = m_formatList.end(), iter--; iter != m_formatList.begin(); iter--)
	{
		formatSt = iter->getStart();
		formatEd = iter->getEnd();

		if (formatEd < st)
			break;

		if (st <= formatSt && ed <= formatEd)
		{
			iterEd= iter;
			st1 = formatEd + 1;

			break;
		}

		if (iter == m_formatList.begin() && formatSt > ed)
			break;
	}

	//如果存在start和end跨越了多个现有的foramt
	if (st0 <= ed0 && st1 <= ed1)
	{
		iterEd++;
		for (iter = iterSt, iter++; iter != iterEd; iter = m_formatList.erase(iter));

		CharacterFormat *newFormat = new CharacterFormat(ed0 + 1, st1 - 1, font, size, style);
		m_formatList.insert(iterEd, newFormat);
	}

	//处理尾边界
	if (st1 <= ed1 && iterEd != m_formatList.begin())
	{
		CharacterFormat *newFormat = new CharacterFormat(ed1 + 1, iterEd->getEnd(), font, size, style);
		m_formatList.insert(iterEd, newFormat);

		iterEd->setStart(ed1 + 1);
	}
}