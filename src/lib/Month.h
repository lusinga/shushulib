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

class Month
{
public:
	Month(void);
	~Month(void);
	static DiZhi* buildZhi(int dzid);
	static int getYueJiang(int month);
};

