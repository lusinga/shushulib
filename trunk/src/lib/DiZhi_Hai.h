#pragma once
#include "yin.h"
#include "shui.h"
#include "dizhi.h"

class DiZhi_Hai :
	public Yin, public Shui, public DiZhi	
{
public:
	DiZhi_Hai(void);
	~DiZhi_Hai(void);

	virtual string getName();
};
