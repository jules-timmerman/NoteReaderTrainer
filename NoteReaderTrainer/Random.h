#pragma once

#include <QtWidgets>


class Random
{

public:
	Random(int d);
	~Random();

	QList<int> generate(QList<int> current, int count);

private:
	int diff;

};

