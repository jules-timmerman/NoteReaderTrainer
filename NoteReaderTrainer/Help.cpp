#include "Help.h"


Help::Help(QWidget* parent)
	: QTextEdit(parent)
{
	QFont font("Arial", 12, QFont::Weight::Bold);

	setupString();

	setFixedSize(400, 400);
	setReadOnly(true);
	setText(text);
	setFont(font);

	show();
}


void Help::setupString() {
	text += "Difficulties : \n"
			" - Easy : Small Jumps between notes\n"
			" - Chaos : All notes have the same probability\n"
			"\n\n"
			"Controls : \n"
			"	LA : 'A'\n"
			"	SI : 'B'\n"
			"	DO : 'C'\n"
			"	RE : 'D'\n"
			"	MI : 'E'\n"
			"	FA : 'F'\n"
			"	SOL : 'G'\n";
}