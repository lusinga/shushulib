#include "Month.h"


DiZhi* Month::buildZhi(int dzid)
{
	dzid = dzid>=0 ? dzid %12: dzid % 12 +12;
	DiZhi* pdz = NULL;
	switch(dzid)
	{
	case DiZhi::DZzi:
		pdz = new DiZhi_Zi();
		break;
	case DiZhi::DZchou:
		pdz = new DiZhi_Chou();
		break;
	case DiZhi::DZyin:
		pdz = new DiZhi_Yin();
		break;
	case DiZhi::DZmao:
		pdz = new DiZhi_Mao();
		break;
	case DiZhi::DZchen:
		pdz = new DiZhi_Chen();
		break;
	case DiZhi::DZsi:
		pdz = new DiZhi_Si();
		break;
	case DiZhi::DZwu:
		pdz = new DiZhi_Wu();
		break;
	case DiZhi::DZwei:
		pdz = new DiZhi_Wei();
		break;
	case DiZhi::DZshen:
		pdz = new DiZhi_Shen();
		break;
	case DiZhi::DZyou:
		pdz = new DiZhi_You();
		break;
	case DiZhi::DZxu:
		pdz = new DiZhi_Xu();
		break;
	case DiZhi::DZhai:
		pdz = new DiZhi_Hai();
		break;
	}

	return pdz;
}

TianGan* Month::buildGan(int tgid)
{

	tgid = (tgid + 10) % 10; 
	TianGan* ptg = NULL;
	switch(tgid)
	{
	case TianGan::TGjia:
		ptg = new TianGan_Jia(); 
		break;
	case TianGan::TGyi:
		ptg = new TianGan_Yi();
		break;
	case TianGan::TGbing:
		ptg = new TianGan_Bing();
		break;
	case TianGan::TGding:
		ptg = new TianGan_Ding();
		break;
	case TianGan::TGwu:
		ptg = new TianGan_Wu();
		break;
	case TianGan::TGji:
		ptg = new TianGan_Ji();
		break;
	case TianGan::TGgeng:
		ptg = new TianGan_Geng();
		break;
	case TianGan::TGxin:
		ptg = new TianGan_Xin();
		break;
	case TianGan::TGren:
		ptg = new TianGan_Ren();
		break;
	case TianGan::TGgui:
		ptg = new TianGan_Gui();
		break;
	}

	return ptg;
}

int Month::getYueJiang(int month)
{
	return (12-month);
}

int Month::getYueJiang(DiZhi* pDZ)
{
	return getYueJiang(pDZ->getMonth());
}

TianGan* Month::wuZiYuanDu(TianGan* pTG, DiZhi* pDZ)
{
	int iTgID = pTG->getTgid();
	int iDzID = pDZ->getDzid();

	int iTG2 = (iTgID % 5) * 2;

	TianGan* pTG2 = buildGan((iTG2+iDzID)%10);

	cout<<"[debug]TianGan = "<<pTG2->getTgid()<<endl;

	return pTG2;
}
