#pragma once
#include "yang.h"
#include "tu.h"
#include "dizhi.h"

class DiZhi_Xu :
	public Yang, public Tu, public DiZhi	
{
public:
	DiZhi_Xu(void);
	~DiZhi_Xu(void);

	virtual string getName();
};
