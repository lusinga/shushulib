#pragma once
#include "yin.h"
#include "shui.h"
#include "tiangan.h"

class TianGan_Gui :
	public Yin, public Shui, public TianGan	
{
public:
	TianGan_Gui(void);
	~TianGan_Gui(void);

	virtual string getName();
};
