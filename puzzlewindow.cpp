#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include "puzzlewindow.h"

/**
 * The PuzzleWindow class constructor.
 * It takes no extra parameter other than a parent. Within the 
 * constructor all components of a puzzle is created:
 *     - a puzzle model
 *     - a puzzle view
 *     - a movement counter display
 *     - a timer display
 * 
 * It also lays out the visible components.
 */
PuzzleWindow::PuzzleWindow(QWidget *parent) :
QWidget(parent)
{
	m_PModel = new PuzzleModel(NUM_ROWS, NUM_COLS, this);
	m_PView = new PuzzleView(m_PModel, this);
	m_Timer = new LCDTimer(this);
	m_Counter = new LCDCounter(0, this);
	
	connect(this, SIGNAL(puzzleStart()),
	        m_Timer, SLOT(startTimer()));
	connect(m_PModel, SIGNAL(puzzleSolved()),
	        m_Timer, SLOT(stopTimer()));   
	connect(m_PModel, SIGNAL(puzzleSolved()),
	        this, SLOT(showStats()));
	connect(m_PModel, SIGNAL(gridChanged()),
	        m_Counter, SLOT(increment()));
	        
	// Lay out widgets.
	QHBoxLayout *hLayout = new QHBoxLayout;
	QVBoxLayout *vLayout = new QVBoxLayout;
	
	hLayout->addWidget(m_Counter);
	hLayout->addSpacing(50);
	hLayout->addWidget(m_Timer);
	
	vLayout->addLayout(hLayout);
	vLayout->addSpacing(10);
	vLayout->addWidget(m_PView);
	
	this->setLayout(vLayout);
	
	emit puzzleStart();
}

/**
 * Function that resets and refreshs every components of the class.
 * @see showStats()
 * @see PuzzleGame::PuzzleGame()
 */
void PuzzleWindow::reset()
{
	m_Timer->reset();
	m_Counter->reset();
	m_PModel->reset();
	m_PView->refresh();
}

/**
 * Function that shows statistics of a solved puzzle.
 * It pops up a message box when a puzzle has been successfully 
 * solved. The message box shows the number of movements and time 
 * taken. It also asks whether the player wants to play another 
 * game or not. If the player clicks 'yes' a new game will be started;
 * if the player clicks 'no' the application quits.
 * @see reset()
 */
void PuzzleWindow::showStats()
{
	QMessageBox::StandardButton answer = QMessageBox::question(this, "Play again?", 
	QString("Moves: %1\nTime: %2").arg(m_Counter->counts()).arg(m_Timer->time()->toString("hh:mm:ss")),
	QMessageBox::Yes|QMessageBox::No, QMessageBox::No);
	
	// If 'yes' start new game.
	if(answer == QMessageBox::Yes)
	{
		reset();
	}
	// If 'no' quit app.
	if(answer == QMessageBox::No)
	{
		qApp->quit();
	}
}
