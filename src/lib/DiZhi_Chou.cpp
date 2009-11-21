#include "DiZhi_Chou.h"

DiZhi_Chou::DiZhi_Chou(void)
{
	this->dzid = DZchou;
}

DiZhi_Chou::~DiZhi_Chou(void)
{
}

string DiZhi_Chou::getName()
{
	return "³ó";
}

int DiZhi_Chou::getXing()
{
	return this->feature;
}