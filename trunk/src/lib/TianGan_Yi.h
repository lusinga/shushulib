#pragma once
#include "yin.h"
#include "tu.h"
#include "tiangan.h"

class TianGan_Yi :
	public Yin, public Tu, public TianGan	
{
public:
	TianGan_Yi(void);
	~TianGan_Yi(void);

	virtual string getName();
protected:
	int tgid;
};
