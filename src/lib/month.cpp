#include "Month.h"
#include <boost/make_shared.hpp>

shared_ptr<DiZhi> Month::buildZhi(int dzid)
{
	dzid = dzid>=0 ? dzid %12: dzid % 12 +12;
	shared_ptr<DiZhi> pdz;
	switch(dzid)
	{
	case DiZhi::DZzi:
		//pdz = new DiZhi_Zi();
		pdz = make_shared<DiZhi_Zi>();
		break;
	case DiZhi::DZchou:
		pdz = make_shared<DiZhi_Chou>();
		break;
	case DiZhi::DZyin:
		pdz = make_shared<DiZhi_Yin>();
		break;
	case DiZhi::DZmao:
		pdz = make_shared<DiZhi_Mao>();
		break;
	case DiZhi::DZchen:
		pdz = make_shared<DiZhi_Chen>();
		break;
	case DiZhi::DZsi:
		pdz = make_shared<DiZhi_Si>();
		break;
	case DiZhi::DZwu:
		pdz = make_shared<DiZhi_Wu>();
		break;
	case DiZhi::DZwei:
		pdz = make_shared<DiZhi_Wei>();
		break;
	case DiZhi::DZshen:
		pdz = make_shared<DiZhi_Shen>();
		break;
	case DiZhi::DZyou:
		pdz = make_shared<DiZhi_You>();
		break;
	case DiZhi::DZxu:
		pdz = make_shared<DiZhi_Xu>();
		break;
	case DiZhi::DZhai:
		pdz = make_shared<DiZhi_Hai>();
		break;
	}

	return pdz;
}

shared_ptr<TianGan> Month::buildGan(int tgid)
{

	tgid = (tgid + 10) % 10; 
	shared_ptr<TianGan> ptg = NULL;
	switch(tgid)
	{
	case TianGan::TGjia:
		ptg = make_shared<TianGan_Jia>(); 
		break;
	case TianGan::TGyi:
		ptg = make_shared<TianGan_Yi>();
		break;
	case TianGan::TGbing:
		ptg = make_shared<TianGan_Bing>();
		break;
	case TianGan::TGding:
		ptg = make_shared<TianGan_Ding>();
		break;
	case TianGan::TGwu:
		ptg = make_shared<TianGan_Wu>();
		break;
	case TianGan::TGji:
		ptg = make_shared<TianGan_Ji>();
		break;
	case TianGan::TGgeng:
		ptg = make_shared<TianGan_Geng>();
		break;
	case TianGan::TGxin:
		ptg = make_shared<TianGan_Xin>();
		break;
	case TianGan::TGren:
		ptg = make_shared<TianGan_Ren>();
		break;
	case TianGan::TGgui:
		ptg = make_shared<TianGan_Gui>();
		break;
	}

	return ptg;
}

int Month::getYueJiang(int month)
{
	return (12-month);
}

int Month::getYueJiang(shared_ptr<DiZhi> pDZ)
{
	return getYueJiang(pDZ->getMonth());
}

shared_ptr<TianGan> Month::wuZiYuanDu(shared_ptr<TianGan> pTG, shared_ptr<DiZhi> pDZ)
{
	int iTgID = pTG->getTgid();
	int iDzID = pDZ->getDzid();

	int iTG2 = (iTgID % 5) * 2;

	shared_ptr<TianGan> pTG2 = buildGan((iTG2+iDzID)%10);

	//cout<<"[debug]TianGan = "<<pTG2->getTgid()<<endl;

	return pTG2;
}
