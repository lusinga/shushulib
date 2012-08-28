#pragma once

#include <boost/shared_ptr.hpp>
#include <string>
#include <boost/make_shared.hpp>

#include "Gua.h"

const int XiuMen   = 0;
const int ShengMen = 7;
const int ShangMen = 6;
const int DuMen    = 5;
const int Jing3Men = 4;
const int SiMen    = 3;
const int Jing1Men = 2;
const int KaiMen   = 1;

const char BaMenName[8][6] = {"休门","开门","惊门","死门","景门","杜门","伤门","生门"};
const int BaMenGua[8] = {BG_Kan,BG_Qian,BG_Dui,BG_Kun,BG_Li,BG_Xun,BG_Zhen,BG_Gen};

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

	//判断是不是吉门
	static inline bool isJiMen(int men)
	{
		//开，休，生为三吉门，居北方三白之方
		return (men == KaiMen || men==XiuMen || men == ShengMen);
	}
};
