#ifndef PUZZLEMODEL_H
#define PUZZLEMODEL_H

#include <QObject>
#include <QList>

/**
 * Model of the puzzle.
 * Derived from QObject, this class models the status of the puzzle. All 
 * the actual movements of the tiles are done in the class.
 */
class PuzzleModel : public QObject
{
	Q_OBJECT

public:	
	PuzzleModel(int rows=0, int cols=0, QObject *parent=0);
	
	void reset();
	int value(int r, int c);
	bool slide(int tilenum);
	/**
	 * Function that returns the number of rows of the puzzle.
	 * @return Number of rows of the puzzle.
	 */
	int rowCount() const {return m_Rows;}
	/**
	 * Function that returns the number of columns of the puzzle.
	 * @return Number of columns of the puzzle.
	 */	
	int colCount() const {return m_Cols;}	
	
signals:
    /**
     * Signal that indicates puzzle grid has changed.
     * When a mouse click results in a change of the puzzle grid model, 
     * this signal will be emitted.
     * @see PuzzleView::refresh()
     */
	void gridChanged();
	/**
	 * Signal that indicates puzzle has been solved.
	 * When the puzzle has been successfully solved,
	 * this signal will be emitted.
	 * @see LCDTimer::stopTimer()
	 * @see PuzzleWindow::showStats()
	 */
	void puzzleSolved();
	
private:
	QList<int> m_Positions;
	int m_Rows;
	int m_Cols;		
};

#endif
