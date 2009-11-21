#include "DiZhi_Wei.h"

DiZhi_Wei::DiZhi_Wei(void)
{
	this->dzid = DZwei;
}

DiZhi_Wei::~DiZhi_Wei(void)
{
}

string DiZhi_Wei::getName()
{
	return "未";
}

int DiZhi_Wei::getXing()
{
	return this->feature;
}