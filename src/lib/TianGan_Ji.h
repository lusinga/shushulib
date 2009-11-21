#pragma once
#include "yin.h"
#include "tu.h"
#include "tiangan.h"

class TianGan_Ji :
	public Yin, public Tu, public TianGan	
{
public:
	TianGan_Ji(void);
	~TianGan_Ji(void);

	virtual string getName();
};
