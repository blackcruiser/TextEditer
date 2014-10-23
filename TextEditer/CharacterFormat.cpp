#include "stdafx.h"
#include "CharacterFormat.h"

CharacterFormat::CharacterFormat(int start, int end, FzFont font, FzSize size, FzStyle style)
{
	m_start = start;
	m_end = end;

	m_font = font;
	m_size = size;
	m_style = style;
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

void CharacterFormat::setFont(FzFont font)
{
	m_font = font;
}

FzFont CharacterFormat::getFont()
{
	return m_font;
}

void CharacterFormat::setSize(FzSize size)
{
	m_size = size;
}
FzSize CharacterFormat::getSize()
{
	return m_size;
}

void CharacterFormat::setStyle(FzStyle style)
{
	m_style = style;
}

FzStyle CharacterFormat::getStyle()
{
	return m_style;
}