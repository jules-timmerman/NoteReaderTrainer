#pragma once

#include "Staff.h"

class FaStaff : public Staff
{


public:
	FaStaff(QWidget* parent);

	enum Note {
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
		LA0,
		SOL0,
		FA0,
		MI0,
		RE0,
		DO0
	};

protected:
	void paintEvent(QPaintEvent* event) override;

};

