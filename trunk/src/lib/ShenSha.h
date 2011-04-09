#pragma once

#include "DiZhi.h"
#include "Tiangan.h"
#include "Ganzhi.h"

class ShenSha
{
public:
	ShenSha(void);
	~ShenSha(void);

	static bool isTianDe(shared_ptr<DiZhi>  pMonth, shared_ptr<TianGan>  pTG);
	static bool isTianDe(shared_ptr<DiZhi>  pMonth, shared_ptr<DiZhi>  pDZ);
	static bool isTianDeHe(shared_ptr<DiZhi>  pMonth, shared_ptr<TianGan>  pTG);

	static bool isYueDe(shared_ptr<DiZhi>  pMonth, int tgid);
	static bool isTianMa(int month, int dzid);
	static bool isDuoMa(int day_dzid, int dzid);
	static bool isJieSha(int day_dzid, int dzid);

};
