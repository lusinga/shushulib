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
const int TianQinXing   = 8;//不管是寄宫还是飞宫，暂放到最后吧

const char JiuXingName[9][10] = {"天蓬星","天心星","天柱星","天芮星","天英星","天辅星","天冲星","天任星","天禽星"};
const char JiuXingAnotherName[9][10] = {"右弼星","文曲星","禄存星","左辅星","贪狼星","武曲星","破军星","英明星","廉贞星"};
const int staticPosition[9] = {BG_Kan,BG_Qian,BG_Dui,BG_Kun,BG_Li,BG_Xun,BG_Zhen,BG_Gen,BG_Zhong};
const int JiuXingWuXing [9] = {SHUI, JIN, JIN, TU,HUO,MU,MU,TU,TU};

class JiuXing
{
public:
	static boost::shared_ptr<std::string> getXingName(int jiu_xing);
	static boost::shared_ptr<std::string> getXingAnotherName(int jiu_xing);
	static int getWuXing(int jiu_xing);
	//获得九星在八卦配合时的原位
	static int getStaticGua(int jiu_xing); 
};
