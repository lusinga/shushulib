#pragma once

#include <boost/shared_ptr.hpp>
#include <string>

#include "Gua.h"
#include "Xing.h"

const int TianFuXing    = 0;
const int TianQinXing   = 1;
const int TianXinXing   = 2;
const int TianChongXing = 3;
const int TianRenXing   = 4;
const int TianPengXing  = 5;
const int TianRuiXing   = 6;
const int TianYingXing  = 7;
const int TianZhuXing   = 8;

const char JiuXingName[9][10] = {"�츨��","������","������","�����","������","������","������","��Ӣ��","������"};
const char JiuXingAnotherName[9][10] = {"������","������","������","�ƾ���","Ӣ����","������","����","̰����","»����"};
const int staticPosition[9] = {BG_Xun, BG_Zhong, BG_Qian, BG_Zhen, BG_Gen, BG_Kan, BG_Kun, BG_Li, BG_Dui};
const int JiuXingWuXing [9] = {MU, TU, JIN, MU, TU, SHUI, TU, HUO, JIN};

class JiuXing
{
public:
	static boost::shared_ptr<std::string> getXingName(int jiu_xing);
	static boost::shared_ptr<std::string> getXingAnotherName(int jiu_xing);
	static int getWuXing(int jiu_xing);
	//��þ����ڰ������ʱ��ԭλ
	static int getStaticGua(int jiu_xing); 
};
