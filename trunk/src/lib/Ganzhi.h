#pragma once

#include <string>
#include <iostream>
#include <boost/scoped_ptr.hpp>

#include "xing.h"
#include "YinYang.h"

using namespace std;

class GanZhi : public YinYang
{
public:

	GanZhi(void);
	virtual ~GanZhi(void);

	virtual int getXing() = 0;
	bool ke(boost::shared_ptr<GanZhi> pgz);
	bool sheng(boost::shared_ptr<GanZhi> pgz);
	virtual string getName() = 0;
	boost::shared_ptr<Xing> buildXing();
};
