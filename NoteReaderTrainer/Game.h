#pragma once


#include <QtWidgets>
#include <QSound>

#include "Staff.h"
#include "SolStaff.h"

#include "Random.h"

#include "Score.h"

class Game : public QWidget
{

public:
	enum class Key {
		SOL,
		FA
	};

	enum Difficulty {
		EASY,
		MEDIUM,
		HARD
	};

	Game(QWidget *parent = nullptr, Key key = Key::SOL, Difficulty difficulty = Difficulty::EASY, int numbers = 25);
	~Game();

	Staff *staff;
	
protected:
	void keyPressEvent(QKeyEvent* event);

	void next();

	void finish();


private:
	// Top Infos
	QWidget* infos;
	QHBoxLayout* infoLayout;
	QLabel *progressLabel;
	QLabel *precisionLabel;

	QVBoxLayout *layout;

	// Game datas
	Key key;
	Difficulty difficulty;
	int numbers;
	
	double precision;
	int left;
	int hit;
	QTime time;

	// Resources
	const QString correctPath = ":/Resources/Sounds/Correct.wav";
	const QString wrongPath = ":/Resources/Sounds/Wrong.wav";
	QSound correct;
	QSound wrong;


	QList<Qt::Key> validKeys;

	QList<int> currentNotes;

	Random *random;

	Score* score;
};
