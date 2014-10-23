#ifndef _PARAGRAPHGLYPH_H_
#define _PARAGRAPYGLYPH_H_

#include "stdafx.h"
#include "BaseGlyph.h"
#include "fzFont.h"
#include "FzSize.h"
#include "FzStyle.h"
#include "CharacterFormat.h"

class ParagraphGlyph : public BaseGlyph
{
public:
	ParagraphGlyph(BaseGlyph *parent);
	virtual ~ParagraphGlyph();

	void format(int start, int end, FzFont font, FzSize size, FzStyle style);

private:
	std::list<BaseGlyph *> m_rowList;
	std::list<CharacterFormat *> m_formatList;

};

#endif