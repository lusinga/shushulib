#pragma once

#include "Month.h"

#include <boost/shared_ptr.hpp>

const int BG_Kan   = 1;
const int BG_Kun   = 2;
const int BG_Zhen  = 3;
const int BG_Xun   = 4;
const int BG_Qian  = 6;
const int BG_Dui   = 7;
const int BG_Gen   = 8;
const int BG_Li    = 9;

const int BG_Zhong = 5;//中五宫，不属于八卦之一

const char GuaName[9][4] = {"坎","坤","震","巽","中","乾","兑","艮","离"};

class BaGua
{
public:
	static boost::shared_ptr<string> getGuaName(int gua);
	static int getPos(int gua);
};
