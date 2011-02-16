#include "Gan_Zhi.h"
#include "Month.h"

Gan_Zhi::Gan_Zhi(int iTG, int iDZ)
{
	this->pTG = Month::buildGan(iTG);
	this->pDZ = Month::buildZhi(iDZ);
}

Gan_Zhi::~Gan_Zhi(void)
{
}

int Gan_Zhi::getXing()
{
	return 0;
}
	
string Gan_Zhi::getName()
{
	return this->pTG->getName()+this->pDZ->getName();
}
