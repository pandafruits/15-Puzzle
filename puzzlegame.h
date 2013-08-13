#ifndef PUZZLEGAME_H
#define PUZZLEGAME_H

#include <QMainWindow>
#include "puzzlewindow.h"

/**
 * The main window of the application.
 * Derived from QMainWindow, this class contains the puzzle game 
 * area and a menu bar.
 */
class PuzzleGame : public QMainWindow
{
	Q_OBJECT
	
public:
	PuzzleGame(QWidget *parent=0,  Qt::WindowFlags flags=0);

private slots:
	void showAbout();
	
private:
	PuzzleWindow *m_PWindow;
};

#endif
