#pragma once

#include <QtWidgets>

class Help : public QTextEdit
{

public:
	Help(QWidget* parent = nullptr);

private:
	QString text;

	void setupString();

};

