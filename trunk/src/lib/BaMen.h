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

const char BaMenName[8][6] = {"����","����","����","����","����","����","����","����"};
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

	//�ж��ǲ��Ǽ���
	static inline bool isJiMen(int men)
	{
		//�����ݣ���Ϊ�����ţ��ӱ�������֮��
		return (men == KaiMen || men==XiuMen || men == ShengMen);
	}
};
