#pragma once
#include "yang.h"
#include "Mu.h"
#include "dizhi.h"

class DiZhi_Yin :
	public Yang, public Mu, public DiZhi	
{
public:
	DiZhi_Yin(void);
	~DiZhi_Yin(void);

	virtual string getName();
};
