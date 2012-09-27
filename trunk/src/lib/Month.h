#pragma once

#include "dizhi.h"
#include "dizhi_zi.h"
#include "dizhi_chou.h"
#include "dizhi_mao.h"
#include "dizhi_yin.h"
#include "dizhi_chen.h"
#include "dizhi_si.h"
#include "dizhi_wu.h"
#include "dizhi_wei.h"
#include "dizhi_shen.h"
#include "dizhi_you.h"
#include "dizhi_xu.h"
#include "dizhi_hai.h"

#include "tiangan.h"
#include "tiangan_jia.h"
#include "tiangan_yi.h"
#include "tiangan_bing.h"
#include "tiangan_ding.h"
#include "tiangan_wu.h"
#include "tiangan_ji.h"
#include "tiangan_geng.h"
#include "tiangan_xin.h"
#include "tiangan_ren.h"
#include "tiangan_gui.h"

#include <boost/shared_ptr.hpp>

const int JQDongZhi   = 0x10; //冬至
const int JQJingZhe   = 0x11; //惊蛰
const int JQXiaoHai   = 0x12; //
const int JQDaHan     = 0x13; //
const int JQChunFen   = 0x14; //
const int JQMangZhong = 0x15; //
const int JQGuYu      = 0x16; //
const int JQXiaoMan   = 0x17; //
const int JQLiChun    = 0x18; //
const int JQLiXia     = 0x19; //
const int JQQingMing  = 0x1a; //
const int JQYuShui    = 0x1b; //

const int JQXiaZhi    = 0x20; //
const int JQBaiLu     = 0x21; 
const int JQXiaoShu   = 0x22;
const int JQQiuFen    = 0x23;
const int JQDaShu     = 0x24;
const int JQLiQiu     = 0x25;
const int JQShuangJiang = 0x26;
const int JQXiaoXue     = 0x27;
const int JQDaXue       = 0x28;
const int JQChuShu      = 0x29;
const int JQLiDong      = 0x2a;
const int JQHanLu       = 0x2b;

/************************************************************************/
/* Month类是主要的工具类的集合
/* 包括：根据数字来构造干支类的对象
/* 求月将的值
/* 五子元遁术
/************************************************************************/
class Month
{
public:
	Month(void);
	~Month(void);
	static boost::shared_ptr<TianGan> buildGan(int tgid);
	static boost::shared_ptr<DiZhi> buildZhi(int dzid);
	static int getYueJiang(int month);
	static int getYueJiang(boost::shared_ptr<DiZhi> pDZ);
	static int getMonthByYueJiang(int yuejiang);
	static boost::shared_ptr<TianGan> wuZiYuanDu(boost::shared_ptr<TianGan> pTG, boost::shared_ptr<DiZhi> pDZ);
	static int getYueJiangByJieQi(int jieqi);

	static int findDiZhiByGuiShen(int riGan, bool isDay, int guiShen);//根据贵神来查对应的地支
};

