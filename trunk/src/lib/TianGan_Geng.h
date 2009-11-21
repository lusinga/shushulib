#pragma once
#include "yang.h"
#include "jin.h"
#include "tiangan.h"

class TianGan_Geng :
	public Yang, public Jin, public TianGan	
{
public:
	TianGan_Geng(void);
	~TianGan_Geng(void);

	virtual string getName();
	virtual int getXing();
};
