#pragma once
#include "ganzhi.h"

#include "Tiangan.h"
#include "DiZhi.h"

class Gan_Zhi :
	public GanZhi
{
public:
	Gan_Zhi(int iTG, int iDZ);
	virtual ~Gan_Zhi(void);

	virtual int getXing();
	
	virtual string getName();

	TianGan* pTG;
	DiZhi* pDZ;
};
