#pragma once

#include "DiZhi.h"
#include "Tiangan.h"
#include "Ganzhi.h"

class ShenSha
{
public:
	ShenSha(void);
	~ShenSha(void);

	static bool isTianDe(DiZhi* pMonth, TianGan* pTG);
	static bool isTianDe(DiZhi* pMonth, DiZhi* pDZ);

	static bool isYueDe(DiZhi* pMonth, TianGan* pTG);
};
