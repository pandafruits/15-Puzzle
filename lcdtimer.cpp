#include <QString>
#include "lcdtimer.h"

/**
 * The LCDTimer class constructor.
 * Takes no extra parameter other than a parent. Constructs a QTimer 
 * and a QTime object. Connects the timeout() signal of the QTimer 
 * object with a function that updates the display.
 */
LCDTimer::LCDTimer(QWidget *parent) : QLCDNumber(NUM_DIGIT, parent)
{
	m_Timer = new QTimer(this);
	m_Time = new QTime(0, 0, 0); // Starts with 00:00:00
	
	setFixedSize(120, 40);
	
	// Set green display with black background.
	setAutoFillBackground(true);
	QPalette Pal = palette();
	Pal.setColor(QPalette::Normal, QPalette::WindowText, Qt::green);
    Pal.setColor(QPalette::Normal, QPalette::Window, Qt::black);
    setPalette(Pal);
	
	// Display '00:00:00' to start with.
	display("00:00:00");
	
	connect(m_Timer, SIGNAL(timeout()),
	        this, SLOT(update()));
}

/**
 * The LCDTimer class destructor.
 * I didn't find a QTime constructor that can be initialized with 
 * a parent. So I guess I should explicitly delete it.
 */
LCDTimer::~LCDTimer()
{
	delete m_Time;
}

/**
 * Function that resets the timer.
 * The times and display is reset to '00:00:00' and the QTimer 
 * member is also re-started.
 * @see PuzzleWindow::reset()
 */
void LCDTimer::reset()
{
	m_Time->setHMS(0, 0, 0);
	display("00:00:00");
	m_Timer->start(1000);
}

/**
 * Function that start the timer.
 * The QTimer member is started with 1000ms timeout.
 */
void LCDTimer::startTimer()
{
	m_Timer->start(1000);
}

/**
 * Function that stops the timer.
 * The QTimer member is stopped.
 */
void LCDTimer::stopTimer()
{
	m_Timer->stop();
}

/**
 * Function that updates the time and display.
 * Everytime the QTimer member times out (1000ms), 
 * this function is called.
 */
void LCDTimer::update()
{
	*m_Time = m_Time->addSecs(1); // Increment by 1s
	
	QString timeStr = m_Time->toString("hh:mm:ss");
	display(timeStr);
}
