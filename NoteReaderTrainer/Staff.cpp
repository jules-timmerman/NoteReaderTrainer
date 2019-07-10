#include "Staff.h"

Staff::Staff(QWidget* parent)
	: QWidget(parent)
{

}


void Staff::setNotes(QList<int> list)
{
	notes = list;
	this->update();
}

void Staff::paintEvent(QPaintEvent* event)
{
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

	QList<QLine> lines;
	for (int i = 0; i < 5; i++) {
		QLine l(0, lineOffset + (i * lineSize), width, lineOffset + (i * lineSize));
		lines += l;
	}
	painter.drawLines(lines.toVector());

}
