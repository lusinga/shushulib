#pragma once
#include "yin.h"
#include "Tu.h"
#include "dizhi.h"

class DiZhi_Wei :
	public Yin, public Tu, public DiZhi	
{
public:
	DiZhi_Wei(void);
	~DiZhi_Wei(void);

	virtual string getName();
};
