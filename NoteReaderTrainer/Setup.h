#pragma once

#include <QtWidgets>
#include "Game.h"
#include "Help.h"

class Setup : public QWidget
{
	Q_OBJECT

public:
	Setup();
	~Setup();

public slots:
	void launch();
	void help();



private:
	QVBoxLayout* layout;

	// Settings
	QWidget * settings;
	QFormLayout * layoutSettings;
	QComboBox *difficulty;
	QComboBox *key;
	QSpinBox* numbers;

	// Buttons
	QWidget* buttons;
	QHBoxLayout* layoutButtons;
	QPushButton *buttonGo;
	QPushButton* buttonHelp;

	Game* game;

	Help* h;

};
