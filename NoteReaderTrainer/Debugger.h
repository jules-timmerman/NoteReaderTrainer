#pragma once

#include <QtWidgets>

class Debugger : QTextEdit
{

public:
	Debugger();

	static void appendToAll(QString text);
	static void appendToAll(double d);
	static void appendToAll(int i);

	static QList<Debugger*> instances;
};

