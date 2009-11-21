#pragma once
#include "yang.h"
#include "huo.h"
#include "dizhi.h"

class DiZhi_Wu :
	public Yang, public Huo, public DiZhi	
{
public:
	DiZhi_Wu(void);
	~DiZhi_Wu(void);

	virtual string getName();
	virtual int getXing();
};
