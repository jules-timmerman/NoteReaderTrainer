#include "Debugger.h"

QList<Debugger*> Debugger::instances; // Instantiate because it is static

Debugger::Debugger() 
	: QTextEdit()
{
	setBaseSize(200, 200);

	this->setWindowTitle("Debugger");
	this->setReadOnly(true);

	instances.append(this);

	show();
}

void Debugger::appendToAll(QString text) {
	for (Debugger* d : instances) {
		d->append(text);
	}
}

void Debugger::appendToAll(double d) {
	Debugger::appendToAll(QString::number(d));
}

void Debugger::appendToAll(int i) {
	Debugger::appendToAll(QString::number(i));
}
