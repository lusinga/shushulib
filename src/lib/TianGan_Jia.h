#pragma once
#include "yang.h"
#include "mu.h"
#include "tiangan.h"

class TianGan_Jia :
	public Yang, public Mu, public TianGan	
{
public:
	TianGan_Jia(void);
	~TianGan_Jia(void);

	virtual string getName();
};
