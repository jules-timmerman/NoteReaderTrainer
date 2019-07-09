#pragma once

#include <QtWidgets>
#include "Staff.h"

class SolStaff : public Staff
{
public:
	SolStaff(QWidget* parent);
	~SolStaff();

	enum Note {
		DO3,
		SI2,
		LA2,
		SOL2,
		FA2,
		MI2,
		RE2,
		DO2,
		SI1,
		LA1,
		SOL1,
		FA1,
		MI1,
		RE1,
		DO1,
		SI0,
		LA0
	};


protected:
	void paintEvent(QPaintEvent* event) override;
};
