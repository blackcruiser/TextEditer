#ifndef _ROWFORMAT_H_
#define _ROWFORMAT_H_

class RowFormat
{
public:
	RowFormat();
	~RowFormat();

	int getWidth();

private:
	int m_width, m_leftIndent, m_rightIndent, firstRowIndent, rowSpace;
	
};

#endif