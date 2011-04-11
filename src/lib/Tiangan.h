#pragma once

#include "GanZhi.h"

#include "dizhi.h"
#include <string>

using namespace std;

const int TGjia  = 0;
const int TGyi   = 1;
const int TGbing = 2;
const int TGding = 3;
const int TGwu   = 4;
const int TGji   = 5;
const int TGgeng = 6;
const int TGxin  = 7;
const int TGren  = 8;
const int TGgui  = 9;

class TianGan : public GanZhi
{
public:
	static int JiGong[];

	//int getDzid(void);
	int getTgid(void);
	int getJiGong();
	int getHe();

protected:
	int tgid;
};
