#include "lcdcounter.h"

/**
 * The LCDCounter class constructor.
 * Doesn't do much. Simply takes an integer as the start count.
 */
LCDCounter::LCDCounter(int startcnt, QWidget *parent) :
QLCDNumber(NUM_DIGIT, parent), m_Counts(startcnt)
{
	setFixedSize(55, 40);
	
	// Set green display with black background.
	setAutoFillBackground(true);
	QPalette Pal = palette();
	Pal.setColor(QPalette::Normal, QPalette::WindowText, Qt::green);
    Pal.setColor(QPalette::Normal, QPalette::Window, Qt::black);
    setPalette(Pal);
}

/**
 * Function that resets the counter.
 * The counts and display are reset to 0.
 * @see PuzzleWindow::reset()
 */
void LCDCounter::reset()
{
	m_Counts = 0;
	display(m_Counts);
}

/**
 * Function that increments the counter.
 * The count is incremented by one then displayed.
 * @see PuzzleWindow::PuzzleWindow()
 */
void LCDCounter::increment()
{
	display(++m_Counts);
}
