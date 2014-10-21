#ifndef _PARAGRAPHFORMAT_H_
#define _PARAGRAPHFORMAT_H_

class ParagraphFormat
{
public:
	ParagraphFormat();
	~ParagraphFormat();

	int getWidth();

private:
	int m_width, m_leftIndent, m_rightIndent, firstRowIndent, rowSpace;
	
};

#endif