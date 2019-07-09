#include "Game.h"

Game::Game(QWidget* parent, Key key, Difficulty difficulty, int numbers)
	: QWidget(parent), key(key), difficulty(difficulty), numbers(numbers),
	correct(correctPath), wrong(wrongPath)
{
	// Other values
	time = QTime::currentTime();
	validKeys = {
		Qt::Key::Key_A,
		Qt::Key::Key_B,
		Qt::Key::Key_C,
		Qt::Key::Key_D,
		Qt::Key::Key_E,
		Qt::Key::Key_F,
		Qt::Key::Key_G
	};

	precision = 0;
	left = numbers;
	hit = 0;


	setFixedSize(800, 600);

	// Staff setup

	staff = new SolStaff(this);

	// Top Infos
	infos = new QWidget(this);
	infoLayout = new QHBoxLayout(infos);
	infos->setLayout(infoLayout);

	progressLabel = new QLabel(QString("Left : %1").arg(left), infos);
	precisionLabel = new QLabel(QString("Precision : %1 %").arg(precision), infos);

	infoLayout->addWidget(progressLabel);
	infoLayout->addWidget(precisionLabel);

	infos->setSizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Maximum);

	// General Layout
	layout = new QVBoxLayout(this);
	layout->addWidget(infos);
	layout->addWidget(staff);

	setLayout(layout);

	// Random
	random = new Random(difficulty);


	currentNotes = { staff->sizeEnum / 2 + 1 }; // Initializing with middle 
	next();
}

Game::~Game() {
	delete random;
	delete score;
}

// Only Function to Redo for CHORD Support
void Game::keyPressEvent(QKeyEvent* event) {
	Qt::Key k = (Qt::Key)event->key();
	// Especially here
	int note = currentNotes[0];
	Qt::Key noteKey;
	
	if (key == Key::SOL) { // CLE DE SOL
		if (note == 0 || note == 7 || note == 14) // DO
			noteKey = validKeys[2];
		if (note == 1 || note == 8 || note == 15) // SI
			noteKey = validKeys[1];
		if (note == 2 || note == 9 || note == 16) // LA
			noteKey = validKeys[0];
		if (note == 3 || note == 10)	// SOL
			noteKey = validKeys[6];
		if (note == 4 || note == 11)	// FA
			noteKey = validKeys[5];
		if (note == 5 || note == 12)	// MI
			noteKey = validKeys[4];
		if (note == 6 || note == 13)	// RE
			noteKey = validKeys[3];
	}
	else { // CLE DE FA

	}

	if (validKeys.contains(k)) { // If a valid key is press
		if (noteKey == k) {
			correct.play();
			hit++;
		}
		else {
			wrong.play();
		}

		left--;
		precision = (hit * 100) / (numbers - left);

		progressLabel->setText(QString("Left : %1").arg(left));
		precisionLabel->setText(QString("Precision : %1 %").arg(precision));

		if (left == 0) {
			finish();
		}
		else {
			next();
		}
	}



}

void Game::finish() {
	score = new Score(precision, hit, numbers, time.elapsed());
	score->show();

	this->hide();
}


void Game::next() {
	currentNotes = random->generate(currentNotes, 1);

	for (int i = 0; i < currentNotes.size(); i++) {
		int& note = currentNotes[i];
		if (note < 0 || note >= staff->sizeEnum) { // if out of range (17+)
			note = (staff->sizeEnum / 2 + 1);
		}
	}


	staff->setNotes(currentNotes);
}