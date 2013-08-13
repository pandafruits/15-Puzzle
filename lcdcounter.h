#ifndef LCDCOUNTER_H
#define LCDCOUNTER_H

#include <QLCDNumber>

/**
 * An LCD counter display.
 * Very simple, derived from QLCDNumber.
 */
class LCDCounter : public QLCDNumber
{
	Q_OBJECT

public:
    /**
     * ENUM for the size (number of digits) of the LCD display.
     */
	enum {NUM_DIGIT = 3};

	LCDCounter(int startcnt=0, QWidget *parent=0);
	
	/**
	 * Function that returns the current count.
	 * @return Current count value.
	 */
	int counts() const {return m_Counts;}
	void reset();

private slots:
	void increment();

private:
	int m_Counts;
};


#endif
