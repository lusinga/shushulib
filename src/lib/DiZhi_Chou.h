#pragma once
#include "yin.h"
#include "tu.h"
#include "dizhi.h"

class DiZhi_Chou :
	public Yin, public Tu, public DiZhi	
{
public:
	DiZhi_Chou(void);
	~DiZhi_Chou(void);

	virtual string getName();
	virtual int getXing();
};
