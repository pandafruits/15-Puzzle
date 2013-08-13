#include <QString>
#include "tile.h"

/**
 * The Tile class constructor.
 * It takes an integer as the tile number. All parameters are optional.
 * @param tileNumber The number that will be shown on the tiles.
 */
Tile::Tile(int tileNumber, QWidget *parent) :
QPushButton(QString("%1").arg(tileNumber), parent), 
m_Number(tileNumber)
{
	// Fix tile size to 56x56
	setFixedSize(56, 56);
	
	// Set button style - just make the number larger
	setStyleSheet(QString("font-size: 18pt;font-weight: bold;"));
}
