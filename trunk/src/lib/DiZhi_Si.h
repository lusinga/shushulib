#pragma once
#include "yin.h"
#include "huo.h"
#include "dizhi.h"

class DiZhi_Si :
	public Yin, public Huo, public DiZhi	
{
public:
	DiZhi_Si(void);
	~DiZhi_Si(void);

	virtual string getName();
	virtual int getXing();
};
