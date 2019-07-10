#include "Setup.h"

Setup::Setup()
	: QWidget()
{

	setBaseSize(200, 200);


	// Setup Settings Widgets
	settings = new QWidget(this);
	layoutSettings = new QFormLayout(settings);
	settings->setLayout(layoutSettings);
	
	key = new QComboBox(this);
	key->addItem("Sol");
	key->addItem("Fa");

	difficulty = new QComboBox(this);
	difficulty->addItem("Easy");
	difficulty->addItem("Medium (WIP)");
	difficulty->addItem("Hard (WIP)");
	difficulty->addItem("Chaos");

	numbers = new QSpinBox(this);
	numbers->setValue(25);
	numbers->setRange(1, 100);


	layoutSettings->addRow("Key to Train : ", key);
	layoutSettings->addRow("Difficulty : ", difficulty);
	layoutSettings->addRow("Number : ", numbers);

	
	
	
	// Buttons
	buttons = new QWidget(this);
	layoutButtons = new QHBoxLayout(buttons);
	buttons->setLayout(layoutButtons);

	buttonGo = new QPushButton("GO!", this);
	QObject::connect(buttonGo, SIGNAL(clicked()), this, SLOT(launch()));

	buttonHelp = new QPushButton("Help", this);
	QObject::connect(buttonHelp, SIGNAL(clicked()), this, SLOT(help()));

	layoutButtons->addWidget(buttonGo);
	layoutButtons->addWidget(buttonHelp);



	// General Layout
	layout = new QVBoxLayout(this);
	layout->addWidget(settings);
	layout->addWidget(buttons);

	setLayout(layout);


}


void Setup::launch() {
	Game::Key k = (Game::Key)key->currentIndex();
	Game::Difficulty d = (Game::Difficulty)difficulty->currentIndex();
	int i = numbers->value();
	
	game = new Game(nullptr, k, d, i);
	game->show();
	this->hide();
}

void Setup::help() {
	h = new Help();
}

Setup::~Setup()
{
	delete game;
	delete h;
}
