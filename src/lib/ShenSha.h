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
	static bool isTianDeHe(DiZhi* pMonth, TianGan* pTG);

	static bool isYueDe(DiZhi* pMonth, int tgid);
	static bool isTianMa(int month, int dzid);
	static bool isDuoMa(int day_dzid, int dzid);
	static bool isJieSha(int day_dzid, int dzid);

};
