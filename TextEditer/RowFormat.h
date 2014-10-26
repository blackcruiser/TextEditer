#ifndef _ROWFORMAT_H_
#define _ROWFORMAT_H_

class RowFormat
{
public:
	RowFormat();
	RowFormat(int width, int leftIndent, int rightIndent, int firstRowIndent, int rowSpace, int wordSpace);
	~RowFormat();

	int getWidth();
	void setWidth(int width);
	int getLeftIndent();
	void setLeftIndent(int indent);
	int getRightIndent();
	void setRightIndent(int indent);
	int getFirstRowIndent();
	void setFirstRowIndent(int indent);
	int getRowSpace();
	void setRowSpace(int space);
	int getWordSpace();
	void setWordSpace(int space);


private:
	int m_width, m_leftIndent, m_rightIndent, m_firstRowIndent, m_rowSpace, m_wordSpace;
	
};

#endif