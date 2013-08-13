#ifndef PUZZLEVIEW_H
#define PUZZLEVIEW_H

#include <QAbstractButton>
#include <QButtonGroup>
#include <QGridLayout>
#include "puzzlemodel.h"

/**
 * View of the puzzle.
 * Derived from QWidget, this class presents the view of the 
 * puzzle. Whenever the puzzle model changes, this class will  
 * reflect the change by rearranging the number tiles.
 */
class PuzzleView : public QWidget
{
	Q_OBJECT
	
public:
	PuzzleView(PuzzleModel *pm, QWidget *parent=0);
	
public slots:
	void refresh();
	
private slots:
	void tryToSlide(QAbstractButton *button);

private:
	PuzzleModel *m_Model;
	QGridLayout *m_Layout;
	QButtonGroup m_Buttons;
};

#endif
