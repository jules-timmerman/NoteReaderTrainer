#include <QtWidgets/QApplication>
#include "Setup.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Setup w;
	w.show();

	//delete w;
	
	return a.exec();
}
