#include "tiangan_ji.h"

TianGan_Ji::TianGan_Ji(void)
{
	this->tgid = TGji;
}

TianGan_Ji::~TianGan_Ji()
{
}

string TianGan_Ji::getName()
{
	return "¼º";
}

int TianGan_Ji::getXing()
{
	return this->feature;
}
