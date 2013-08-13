#include "puzzleview.h"
#include "tile.h"

/**
 * The PuzzleView class constructor.
 * It takes a PuzzleModel pointer, then layout a grid of tiles 
 * accroding to the model.
 */
PuzzleView::PuzzleView(PuzzleModel *pm, QWidget *parent) :
QWidget(parent), m_Model(pm)
{
	// Construct and install a grid layout to the PuzzleView widget.
	// Passing 'this' as parent now is equivalent to calling 
	// setLayout(m_Layout) later.
	m_Layout = new QGridLayout(this);
	
	m_Layout->setContentsMargins(0, 0, 0, 0);
	m_Layout->setSpacing(0);
	
	int numRows = m_Model->rowCount();
	int numCols = m_Model->colCount();
	
	// Add 15 buttons to button group and lay them out.
	for(int r = 0; r < numRows; ++r)
	{
		for(int c = 0; c < numCols; ++c)
		{
			int id = m_Model->value(r, c);
			if(id != 0)
			{
				Tile *t = new Tile(id);
				m_Buttons.addButton(t, id); // Button ID 1 ~ 15.
				m_Layout->addWidget(t, r, c);
			}
		}
	}
		
	// Refresh puzzle view when puzzle model changes.
	connect(m_Model, SIGNAL(gridChanged()),
	        this, SLOT(refresh()));
	
	// Try sliding cells when a button is clicked.     
	connect(&m_Buttons, SIGNAL(buttonClicked(QAbstractButton *)),
	        this, SLOT(tryToSlide(QAbstractButton *)));
}

/**
 * Function that attempts to slide the tiles.
 * @param button Pointer to the button being clicked.
 */
void PuzzleView::tryToSlide(QAbstractButton *button)
{
	m_Model->slide(qobject_cast<Tile *>(button)->tileNum());
}

/**
 * Function that refreshes the puzzle view.
 * This function refreshes the puzzle view by first removing
 * all tiles in the layout then replacing them as per the model.
 */
void PuzzleView::refresh()
{
	int numRows = m_Model->rowCount();
	int numCols = m_Model->colCount();
	
	// Remove all buttons first.
	for(int id = 1; id < numRows*numCols; ++id)
	{
		m_Layout->removeWidget(m_Buttons.button(id));
	}
	
	// Then re-layout all buttons.
	for(int r = 0; r < numRows; ++r)
	{
		for(int c = 0; c < numCols; ++c)
		{
			int id = m_Model->value(r, c);
			if(id != 0)
			{
				m_Layout->addWidget(m_Buttons.button(id), r, c);
			}
		}
	}
}

