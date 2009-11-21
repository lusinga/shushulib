#pragma once
#include "yin.h"
#include "jin.h"
#include "dizhi.h"

class DiZhi_You :
	public Yin, public Jin, public DiZhi	
{
public:
	DiZhi_You(void);
	~DiZhi_You(void);

	virtual string getName();
	virtual int getXing();
};
