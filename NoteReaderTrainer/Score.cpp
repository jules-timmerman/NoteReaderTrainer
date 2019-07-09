#include "Score.h"


Score::Score(double precision, int hit, int total, int time)
	: QWidget(), precision(precision), hit(hit), total(total), time(time)
{

	QFont font("Arial", 12, QFont::Weight::Bold);

	setFixedSize(400, 400);

	precisionLabel = new QLabel(QString("Precision : %1 %").arg(precision), this);
	hitLabel = new QLabel(QString("Number Correct : %1").arg(hit), this);
	totalLabel = new QLabel(QString("Number of Notes : %1").arg(total), this);
	timeLabel = new QLabel(QString("Completed in %1 minutes %2 secondes").arg(time / 1000 / 60).arg(time / 1000), this);

	precisionLabel->setAlignment(Qt::AlignCenter);
	hitLabel->setAlignment(Qt::AlignCenter);
	totalLabel->setAlignment(Qt::AlignCenter);
	timeLabel->setAlignment(Qt::AlignCenter);

	precisionLabel->setFont(font);
	hitLabel->setFont(font);
	totalLabel->setFont(font);
	timeLabel->setFont(font);


	layout = new QVBoxLayout(this);
	layout->addWidget(precisionLabel);
	layout->addWidget(hitLabel);
	layout->addWidget(totalLabel);
	layout->addWidget(timeLabel);

	setLayout(layout);

}