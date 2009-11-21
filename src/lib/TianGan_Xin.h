#pragma once
#include "yin.h"
#include "jin.h"
#include "tiangan.h"

class TianGan_Xin :
	public Yin, public Jin, public TianGan	
{
public:
	TianGan_Xin(void);
	~TianGan_Xin(void);

	virtual string getName();
	virtual int getXing();
};
