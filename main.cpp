#include <QtGui>
#include "puzzlegame.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	PuzzleGame game;
	game.show();
	
	return app.exec();
}
