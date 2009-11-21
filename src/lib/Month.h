#pragma once

#include "dizhi.h"
#include "dizhi_zi.h"
#include "dizhi_mao.h"
#include "dizhi_yin.h"

class Month
{
public:
	Month(void);
	~Month(void);
	static DiZhi* buildZhi(int dzid);
};

