#include <QtGlobal>
#include <QTime>
#include "puzzlemodel.h"

/**
 * The PuzzleModel class constructor.
 * It takes a row number and a column number to construct a 
 * puzzle model. All parameters are optional.
 * @param rows Number of rows of the puzzle.
 * @param cols Number of colomns of the puzzle.
 */
PuzzleModel::PuzzleModel(int rows, int cols, QObject *parent) :
QObject(parent), m_Rows(rows), m_Cols(cols)
{
	reset();
}

/**
 * Function that resets the puzzle model.
 * It first populates the puzzle numbers sequentially in an integer list.
 * Then the function shuffles these numbers.
 * @see PuzzleWindow::showStats()
 * @see PuzzleWindow::reset()
 */
void PuzzleModel::reset()
{
	// Populate m_Position first. For a 4 x 4 puzzle, 
	// it's like this:
	//          1  2  3  4
	//          5  6  7  8
	//          9 10 11 12
	//         13 14 15  0
	if(m_Positions.isEmpty())
	{
		for(int i = 1; i <= m_Rows*m_Cols; ++i)
		{
			m_Positions.append(i % (m_Rows*m_Cols));
		}
	}
	else
	{
		for(int i = 1; i <= m_Rows*m_Cols; ++i)
		{
			m_Positions[i-1] = i % (m_Rows*m_Cols);
		}		
	}
	
	// Then randomly swap position 0~14 for 50 times
	QTime time = QTime::currentTime();
	qsrand((uint)time.msec());
	for(int i = 0; i < 50; ++i)
	{
		int posA = qrand() % (m_Rows*m_Cols - 1);
		int posB = qrand() % (m_Rows*m_Cols - 1);
		
		m_Positions.swap(posA, posB);
	}
}

/**
 * Function that retrives the value at a particular position in the model.
 * @param r Row number.
 * @param c Column number.
 * @return Number at position [r, c].
 */
int PuzzleModel::value(int r, int c) 
{
	return m_Positions[r*m_Cols + c];
}

/**
 * Function that tries to slide the modelled tile numbers.
 * This function tries to rearrange the modelled tile numbers as an 
 * effect of a sliding action.
 * @param tilenum Tile number clicked.
 * @return true if sliding possible, false if not.
 */
bool PuzzleModel::slide(int tilenum)
{
	int destIndex, srcIndex;
	
	destIndex = m_Positions.indexOf(0); // Index of empty cell to be moved into
	srcIndex = m_Positions.indexOf(tilenum); // Index of button clicked to be emptied
	
	// Not slide-able
	if((destIndex / m_Cols != srcIndex / m_Cols) &&
	   (destIndex % m_Cols != srcIndex % m_Cols))
	{
		return false;
	}
	// Same row - slide-able so slide
	else if(destIndex / m_Cols == srcIndex / m_Cols)
	{
		if(destIndex < srcIndex)
		{
			while(destIndex < srcIndex)
			{
				m_Positions.swap(destIndex, destIndex + 1);
				++destIndex;
			}
		}
		if(destIndex > srcIndex)
		{
			while(destIndex > srcIndex)
			{
				m_Positions.swap(destIndex, destIndex - 1);
				--destIndex;
			}
		}
	}
	// Same col - slide-able so slide
	else if(destIndex % m_Cols == srcIndex % m_Cols)
	{	
		if(destIndex < srcIndex)
		{
			while(destIndex < srcIndex)
			{
				m_Positions.swap(destIndex, destIndex + m_Cols);
				destIndex += m_Cols;
			}
		}
		if(destIndex > srcIndex)
		{
			while(destIndex > srcIndex)
			{
				m_Positions.swap(destIndex, destIndex - m_Cols);
				destIndex -= m_Cols;
			}		
		}
	}
	
	emit gridChanged();
	
	// Check whether puzzle solved, if so emit puzzleSolved signal
	for(int i = 0; i < m_Rows*m_Cols-1; ++i)
	{
		if(m_Positions[i] != i + 1)
		{
			return true;
		}
	}	
	emit puzzleSolved();
	return true;
}
