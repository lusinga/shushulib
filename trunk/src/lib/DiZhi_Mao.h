#pragma once
#include "yin.h"
#include "mu.h"
#include "dizhi.h"

class DiZhi_Mao :
	public Yin, public Mu, public DiZhi
{
public:
	DiZhi_Mao(void);
	~DiZhi_Mao(void);

	virtual string getName();
};
