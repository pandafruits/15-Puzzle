#ifndef LCDTIMER_H
#define LCDTIMER_H

#include <QWidget>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>

/**
 * An LCD timer display.
 * Derived from QLCDNumber, this class is implemented as 
 * a 24 hour timer.
 */
class LCDTimer : public QLCDNumber
{
	Q_OBJECT
	
public:
    /**
     * ENUM for the size (number of digits) of the LCD display.
     */
	enum {NUM_DIGIT = 8};
	explicit LCDTimer(QWidget *parent=0);
	~LCDTimer();
	
	/**
	 * Function that returns the time elapsed.
	 * @return Constant pointer to the QTime member.
	 */
	const QTime* time() const {return m_Time;}
	void reset();

private slots:
	void startTimer();
	void stopTimer();
	void update();

private:
	QTimer *m_Timer;
	QTime *m_Time;
};

#endif
