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

bool Gan_Zhi::isXunKong(DiZhi* pDZToBeCheck)
{
	int tgid = pTG->getTgid();
	int dzid = pDZ->getDzid();

	int xunid = (dzid - tgid + 12) % 12;

	bool bResult;

	if(xunid == DiZhi::DZzi)
	{
		bResult = (pDZToBeCheck->getDzid() == DiZhi::DZxu ||pDZToBeCheck->getDzid() == DiZhi::DZhai);
	}
	else if(xunid == DiZhi::DZxu)
	{
		bResult = (pDZToBeCheck->getDzid() == DiZhi::DZshen ||pDZToBeCheck->getDzid() == DiZhi::DZyou);
	}
	else if(xunid == DiZhi::DZshen)
	{
		bResult = (pDZToBeCheck->getDzid() == DiZhi::DZwu ||pDZToBeCheck->getDzid() == DiZhi::DZwei);
	}
	else if(xunid == DiZhi::DZwu)
	{
		bResult = (pDZToBeCheck->getDzid() == DiZhi::DZchen ||pDZToBeCheck->getDzid() == DiZhi::DZsi);
	}
	else if(xunid == DiZhi::DZchen)
	{
		bResult = (pDZToBeCheck->getDzid() == DiZhi::DZyin ||pDZToBeCheck->getDzid() == DiZhi::DZmao);
	}
	else if(xunid == DiZhi::DZyin)
	{
		bResult = (pDZToBeCheck->getDzid() == DiZhi::DZzi ||pDZToBeCheck->getDzid() == DiZhi::DZchou);
	}
	else
		bResult = false;

	return bResult;
}

bool Gan_Zhi::isSiDaKongWang(int xing)
{
	int tgid = pTG->getTgid();
	int dzid = pDZ->getDzid();

	int xunid = (dzid - tgid + 12) % 12;

	bool bResult = false;

	if(xunid == DiZhi::DZzi || xunid == DiZhi::DZwu)
	{
		bResult = xing == Xing::SHUI;
	}
	else if(xunid == DiZhi::DZyin || xunid == DiZhi::DZshen)
	{
		bResult = xing == Xing::JIN;
	}
	else
		bResult = false;
	
	return bResult;
}
