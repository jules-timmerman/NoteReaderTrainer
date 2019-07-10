#pragma once

#include <QtWidgets>

class Staff : public QWidget
{

public:
	Staff(QWidget* parent);

	void setNotes(QList<int> list);

	int sizeEnum = 17;

protected:
	QList<int> notes;

	virtual void paintEvent(QPaintEvent* event);

};

