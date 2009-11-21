#pragma once
#include "yang.h"
#include "huo.h"
#include "tiangan.h"

class TianGan_Bing :
	public Yang, public Huo, public TianGan	
{
public:
	TianGan_Bing(void);
	~TianGan_Bing(void);

	virtual string getName();
protected:
	int tgid;
};
