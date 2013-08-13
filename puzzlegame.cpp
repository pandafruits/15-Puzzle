#include <QApplication>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include "puzzlegame.h"

/**
 * The PuzzleGame class constructor.
 * It creates a PuzzleWindow object as the central widget, 
 * constructs and connects menus.
 */
PuzzleGame::PuzzleGame(QWidget *parent, Qt::WindowFlags flags) :
QMainWindow(parent, flags)
{
	QMenu *fileMenu = menuBar()->addMenu("&File");
	QMenu *helpMenu = menuBar()->addMenu("&Help");
	
	QAction *newGameAction = fileMenu->addAction("&New Game");
	QAction *quitAction = fileMenu->addAction("&Quit");
	QAction *aboutAction = helpMenu->addAction("&About");
	
	m_PWindow = new PuzzleWindow(this);
	setCentralWidget(m_PWindow);
	
	setFixedSize(250, 330);
	setWindowTitle("15-Puzzle");
	
	connect(newGameAction, SIGNAL(triggered()),
	        m_PWindow, SLOT(reset()));
	connect(quitAction, SIGNAL(triggered()),
	        qApp, SLOT(quit()));
	connect(aboutAction, SIGNAL(triggered()),
	        this, SLOT(showAbout()));	        
}

/**
 * Functions that pops up the 'About' box.
 * It is called when the 'About' menu item is triggered.
 */
void PuzzleGame::showAbout()
{
	QMessageBox::about(this, "About", "This is the 'About' box!");
}
