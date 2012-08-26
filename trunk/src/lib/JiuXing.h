#pragma once

#include <boost/shared_ptr.hpp>
#include <string>

#include "Gua.h"
#include "Xing.h"

const int TianPengXing  = 0;
const int TianXinXing   = 1;
const int TianZhuXing   = 2;
const int TianRuiXing   = 3;
const int TianYingXing  = 4;
const int TianFuXing    = 5;
const int TianChongXing = 6;
const int TianRenXing   = 7;
const int TianQinXing   = 8;//�����ǼĹ����Ƿɹ����ݷŵ�����

const char JiuXingName[9][10] = {"������","������","������","������","��Ӣ��","�츨��","�����","������","������"};
const char JiuXingAnotherName[9][10] = {"������","������","»����","����","̰����","������","�ƾ���","Ӣ����","������"};
const int staticPosition[9] = {BG_Kan,BG_Qian,BG_Dui,BG_Kun,BG_Li,BG_Xun,BG_Zhen,BG_Gen,BG_Zhong};
const int JiuXingWuXing [9] = {SHUI, JIN, JIN, TU,HUO,MU,MU,TU,TU};

class JiuXing
{
public:
	static boost::shared_ptr<std::string> getXingName(int jiu_xing);
	static boost::shared_ptr<std::string> getXingAnotherName(int jiu_xing);
	static int getWuXing(int jiu_xing);
	//��þ����ڰ������ʱ��ԭλ
	static int getStaticGua(int jiu_xing); 
};
