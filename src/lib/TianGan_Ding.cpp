#include "tiangan_ding.h"

TianGan_Ding::TianGan_Ding(void)
{
	this->tgid = TGding;
}

TianGan_Ding::~TianGan_Ding()
{
}

string TianGan_Ding::getName()
{
	return "¶¡";
}

int TianGan_Ding::getXing()
{
	return this->feature;
}
