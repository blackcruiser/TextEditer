#ifndef _PARAGRAPHGLYPH_H_
#define _PARAGRAPYGLYPH_H_

#include "BaseGlyph.h"
#include "CharacterFormat.h"

class ParagraphGlyph : public BaseGlyph
{
public:
	ParagraphGlyph(BaseGlyph *parent);
	virtual ~ParagraphGlyph();

	void format(int start, int end, fzFont font, fzSize size, fzStyle style);

private:
	std::list<BaseGlyph *> m_rowList;
	std::list<CharacterFormat *> m_formatList;

};

#endif