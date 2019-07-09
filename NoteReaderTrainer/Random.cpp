#include "Random.h"


Random::Random(int d) 
	: diff(d)
{

}

Random::~Random() {

}

QList<int> Random::generate(QList<int> current, int count) {

	QRandomGenerator *generator = QRandomGenerator::global();
	QList<int> list;

	for (int i = 0; i < current.size(); i++) {
		int note = current[i];

		int r = generator->bounded(100);


		// On rappelle que Haut = - et Bas = + (From top to bottom)
		switch (diff)
		{
		case 0:

			// 20% staying the same notes
			if (0 <= r && r < 20) {		
				list << note;
			}

			// 50% going 1 up or down
			if (20 <= r && r < 70) {
				if (generator->generateDouble() < 0.5) {
					list << note + 1;
				}
				else {
					list << note - 1;
				}
			}

			// 30% going 2 up or down
			if (70 <= r && r < 100) { 
				if (generator->generateDouble() < 0.5) {
					list << note + 2;
				}
				else {
					list << note - 2;
				}
			}
			
			
			break;
		case 1:
			break;
		case 2:
			break;
		default:
			break;
		}


		if (i+1 == count)
			return list;
	}

	return list;
}
