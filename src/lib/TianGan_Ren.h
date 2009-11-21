#pragma once
#include "yang.h"
#include "shui.h"
#include "tiangan.h"

class TianGan_Ren :
	public Yang, public Shui, public TianGan	
{
public:
	TianGan_Ren(void);
	~TianGan_Ren(void);

	virtual string getName();
};
