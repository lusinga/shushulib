#pragma once
#include "yin.h"
#include "huo.h"
#include "tiangan.h"

class TianGan_Ding :
	public Yin, public Huo, public TianGan	
{
public:
	TianGan_Ding(void);
	~TianGan_Ding(void);

	virtual string getName();
};
