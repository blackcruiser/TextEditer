#include "stdafx.h"
#include "CharacterFormat.h"

CharacterFormat::CharacterFormat()
{

}

CharacterFormat::~CharacterFormat()
{

}

int CharacterFormat::getStart()
{
	return m_start;
}

int CharacterFormat::getEnd()
{
	return m_end;
}

void CharacterFormat::setStart(int start)
{
	m_start = start;
}

void CharacterFormat::setEnd(int end)
{
	m_end = end;
}

void CharacterFormat::setFont(fzFont font)
{
	m_font = font;
}

fzFont CharacterFormat::getFont()
{
	return m_font;
}

void CharacterFormat::setSize(fzSize size)
{
	m_size = size;
}
fzSize CharacterFormat::getSize()
{
	return m_size;
}

void CharacterFormat::setStyle(fzStyle style)
{
	m_style = style
}

fzStyle CharacterFormat::getStyle()
{
	return m_style;
}