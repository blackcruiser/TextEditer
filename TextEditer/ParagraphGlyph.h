#ifndef _PARAGRAPHGLYPH_H_
#define _PARAGRAPYGLYPH_H_

#include "BaseGlyph.h"

class ParagraphGlyph : public BaseGlyph
{
public:
	ParagraphGlyph(BaseGlyph *parent);
	virtual ~ParagraphGlyph();

	virtual void draw(HDC hdc, Rect boundBox);
	void format();

private:
	std::list<BaseGlyph *> m_rowList;
	std::list<CharacterFormat *> m_formatList;

};

#endif