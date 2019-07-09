#pragma once

#include <QtWidgets>
#include "Game.h"

class Setup : public QWidget
{
	Q_OBJECT

public:
	Setup();
	~Setup();

public slots:
	void launch();



private:
	QVBoxLayout* layout;

	// Settings
	QWidget * settings;
	QFormLayout * layoutSettings;
	QComboBox *difficulty;
	QComboBox *key;
	QSpinBox* numbers;

	// Buttons
	QPushButton *buttonGo;


	Game* game;

};
