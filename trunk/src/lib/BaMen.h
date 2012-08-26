#pragma once

#include <boost/shared_ptr.hpp>
#include <string>
#include <boost/make_shared.hpp>

#include "Gua.h"

const int XiuMen   = 0;
const int ShengMen = 1;
const int ShangMen = 2;
const int DuMen    = 3;
const int Jing3Men = 4;
const int SiMen    = 5;
const int Jing1Men = 6;
const int KaiMen   = 7;

const char BaMenName[8][6] = {"休门","生门","伤门","杜门","景门","死门","惊门","开门"};
const int BaMenGua[8] = {BG_Kan, BG_Gen, BG_Zhen, BG_Xun, BG_Li, BG_Kun, BG_Dui, BG_Qian};

class BaMen
{
public:
	static inline boost::shared_ptr<std::string> getBaMenName(int men)
	{
		return boost::make_shared<std::string>(BaMenName[men%8]);
	}

	static inline int getBaMenGua(int men)
	{
		return BaMenGua[men % 8];
	}
};
