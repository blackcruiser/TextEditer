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
	int st0, ed0, st1, ed1, formatSt, formatEd, tempSt, tempEd;

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

		if (iter == m_formatList.end() && formatSt > ed)
			break;
	}


	{
		// formatSt <= st <= formatEd
		if (iter->contain(st))
		{
			formatSt = iter->getStart();
			formatEd = iter->getEnd();
			formatFont = iter->getFont();
			formatSize = iter->getSize();
			formatStyle = iter->getStyle();


			while (formatSt == st && formatEd < ed)
			{

			}
			/*
			*	Only 4 cases
			*	1. formatSt == st && formatSt <= ed < formatEd
			*	2. formatSt == st && formatEd <= ed
			*	3. formatSt < st <= formatEd && formatSt <= ed < formatEd
			*   4. formatSt < st <= formatEd && formatEd <= ed
			*/

			if (formatEd <= ed)
			{
				iter->setStart(st)
				iter->setFont(font);
				iter->setSize(size);
				iter->setStyle(style);
			}
			else
			{
				CharacterFormat *newFormat = new CharacterFomrat(formatSt, ed, font, size, style);

				m_formatList.insert(iter, newFormat);
				iter->setStart(ed + 1);
			}

			if (formatSt < st)
			{
				CharacterFomrat *newForamt = new CharacterForat(formatSt, st - 1, formatFont, formatSize, formatStyle);

				m_formatList.insert(iter, newFormat);
				iter->setStart(st);
			}


			if (ed <= formatEd)
				break;
		}
	}


}