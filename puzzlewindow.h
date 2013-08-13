#ifndef PUZZLEWINDOW_H
#define PUZZLEWINDOW_H

#include "puzzlemodel.h"
#include "puzzleview.h"
#include "lcdtimer.h"
#include "lcdcounter.h"

/**
 * The main area of the puzzle.
 * Derived from QWidget, this class represents the main game area.
 * It contains the view of the puzzle and the underlying model, a 
 * movement counter and a timer.
 */
class PuzzleWindow : public QWidget
{
	Q_OBJECT
	
public:
    /**
     * ENUM's for puzzle row and column numbers.
     */ 
    enum {
		      NUM_ROWS = 4, /**< Number of puzzle rows */
              NUM_COLS = 4  /**< Number of puzzle columns */
         };
	explicit PuzzleWindow(QWidget *parent=0);
	
signals:
    /**
     * Signal that indicates the start of a puzzle.
     * When an object of this class has been constructed, the 
     * puzzleStart() signal will be emitted.
     * @see LCDTimer::startTimer()
     */
	void puzzleStart();
	
private slots:
	void reset();
    void showStats();	
	
private:
	PuzzleModel *m_PModel;
	PuzzleView *m_PView;
	LCDTimer *m_Timer;
	LCDCounter *m_Counter;
};

#endif
