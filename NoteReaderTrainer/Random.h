#pragma once

#include <QtWidgets>


class Random
{

public:
	Random(int d);

	QList<int> generate(QList<int> current, int count);

private:
	int diff;

};

