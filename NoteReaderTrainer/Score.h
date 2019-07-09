#pragma once

#include <QtWidgets>

class Score : public QWidget
{

public:
	Score(double precision, int hit, int total, int time);


private:
	double precision;
	int hit;
	int total;
	int time;

	QVBoxLayout* layout;
	QLabel* precisionLabel;
	QLabel* hitLabel;
	QLabel* totalLabel;
	QLabel* timeLabel;


};

