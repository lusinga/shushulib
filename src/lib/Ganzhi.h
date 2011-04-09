#pragma once

#include <string>
#include <iostream>
#include <boost/scoped_ptr.hpp>

#include "xing.h"

using namespace std;

class GanZhi
{
public:

	GanZhi(void);
	virtual ~GanZhi(void);

	virtual int getXing() = 0;
	bool ke(shared_ptr<GanZhi> pgz);
	bool sheng(shared_ptr<GanZhi> pgz);
	virtual string getName() = 0;
	shared_ptr<Xing> buildXing();
};
