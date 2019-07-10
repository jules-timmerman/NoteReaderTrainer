#include "FaStaff.h"


FaStaff::FaStaff(QWidget* parent)
	: Staff(parent)
{

}


void FaStaff::paintEvent(QPaintEvent* event) {
	Staff::paintEvent(event);

	QPainter painter(this);

	QBrush brush(Qt::GlobalColor::black);
	QPen pen(brush, 2);

	painter.setBrush(brush);
	painter.setPen(pen);


	// Drawing Staff
	int width = this->width();
	int height = this->height();

	int noteSize = height / (sizeEnum + 2); // +2 to add some space on sides*
	int lineSize = 2 * noteSize; // Distance between 2 lines ( = 2 notes)
	int lineOffset = 5 * noteSize; // Position of the first line (first blank + 4 notes)

	// Drawing Notes
	for (int n : notes) {
		int noteNumber = (int)n;
		int x = 0.1 * width; // Offset on the left (0.1 is arbitrary)
		int y = noteNumber * noteSize;
		int heightEllipse = lineSize;
		int widthEllipse = heightEllipse;

		painter.drawEllipse(x, y, widthEllipse, heightEllipse);

		if (noteNumber % 2 == 0) { // If note is even (meaning we have to draw a sub line)
			int heightLine = y + (heightEllipse / 2);
			painter.drawLine(x - (widthEllipse * 0.2), heightLine, x + (widthEllipse * 1.2), heightLine); // 0.2 and 1.2 is arbitrary
		}

		if (n == Note::MI2 || n == Note::RE2) { // If note is 0 cad MI2, we need to draw a second line on the bottom (DO2)
			int heightLine = 2 * noteSize + (heightEllipse / 2); // Line for DO2
			painter.drawLine(x - (widthEllipse * 0.2), heightLine, x + (widthEllipse * 1.2), heightLine);
		}

		if (n == Note::DO0 || n == Note::RE0) { // Same as above but with DO0 and MI0
			int heightLine = 14 * noteSize + (heightEllipse / 2); // Line for MI0
			painter.drawLine(x - (widthEllipse * 0.2), heightLine, x + (widthEllipse * 1.2), heightLine);
		}

	}
}