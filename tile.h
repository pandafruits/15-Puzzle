#ifndef TILE_H
#define TILE_H

#include <QPushButton>

/**
 * Used as tiles of the game.
 * Derived from QPushButton, this class is used as tiles that can be 
 * moved around.
 */
class Tile : public QPushButton
{
	Q_OBJECT
	
public:
	Tile(int tileNumber=0, QWidget *parent=0);
	/**
	 * Function that returns the tile number.
	 * @return The tile number.
	 */
	int tileNum() {return m_Number;}
		
private:
	int m_Number; 
};

#endif
