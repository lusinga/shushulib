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

class Month
{
public:
	Month(void);
	~Month(void);
	static TianGan* buildGan(int tgid);
	static DiZhi* buildZhi(int dzid);
	static int getYueJiang(int month);
};

