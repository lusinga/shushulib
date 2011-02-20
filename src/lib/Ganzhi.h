#pragma once

#include <string>
#include <iostream>

#include "xing.h"

using namespace std;

class GanZhi
{
public:

	GanZhi(void);
	virtual ~GanZhi(void);

	virtual int getXing() = 0;
	bool ke(GanZhi* pgz);
	virtual string getName() = 0;
	Xing* buildXing();

protected:
	int dzid;
};
