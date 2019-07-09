#include "Setup.h"

Setup::Setup()
	: QWidget()
{

	setBaseSize(200, 200);


	// Setup Settings Widgets
	layoutSettings = new QFormLayout(this);

	settings = new QWidget(this);
	settings->setLayout(layoutSettings);
	
	key = new QComboBox(this);
	key->addItem("Sol");
	key->addItem("Fa");

	difficulty = new QComboBox(this);
	difficulty->addItem("Easy");
	difficulty->addItem("Medium");
	difficulty->addItem("Hard");

	numbers = new QSpinBox(this);
	numbers->setValue(25);
	numbers->setRange(1, 100);


	layoutSettings->addRow("Key to Train : ", key);
	layoutSettings->addRow("Difficulty : ", difficulty);
	layoutSettings->addRow("Number : ", numbers);

	
	
	
	// Button
	buttonGo = new QPushButton("GO!", this);
	QObject::connect(buttonGo, SIGNAL(clicked()), this, SLOT(launch()));


	// General Layout
	layout = new QVBoxLayout(this);
	layout->addWidget(settings);
	layout->addWidget(buttonGo);

	setLayout(layout);


}


void Setup::launch() {
	
	game = new Game(nullptr);
	game->show();
	this->hide();
}

Setup::~Setup()
{
	delete game;
}
