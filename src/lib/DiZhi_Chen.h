#pragma once
#include "yang.h"
#include "tu.h"
#include "dizhi.h"

class DiZhi_Chen :
	public Yang, public Tu, public DiZhi	
{
public:
	DiZhi_Chen(void);
	~DiZhi_Chen(void);

	virtual string getName();
	virtual int getXing();
};
