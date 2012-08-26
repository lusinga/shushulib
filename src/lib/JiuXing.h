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

const char JiuXingName[9][10] = {"天辅星","天禽星","天心星","天冲星","天任星","天蓬星","天芮星","天英星","天柱星"};
const char JiuXingAnotherName[9][10] = {"武曲星","廉贞星","文曲星","破军星","英明星","右弼星","左辅星","贪狼星","禄存星"};
const int staticPosition[9] = {BG_Xun, BG_Zhong, BG_Qian, BG_Zhen, BG_Gen, BG_Kan, BG_Kun, BG_Li, BG_Dui};
const int JiuXingWuXing [9] = {MU, TU, JIN, MU, TU, SHUI, TU, HUO, JIN};

class JiuXing
{
public:
	static boost::shared_ptr<std::string> getXingName(int jiu_xing);
	static boost::shared_ptr<std::string> getXingAnotherName(int jiu_xing);
	static int getWuXing(int jiu_xing);
	//获得九星在八卦配合时的原位
	static int getStaticGua(int jiu_xing); 
};
