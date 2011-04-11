#include "Month.h"
#include <boost/make_shared.hpp>

using boost::make_shared;

shared_ptr<DiZhi> Month::buildZhi(int dzid)
{
	dzid = dzid>=0 ? dzid %12: dzid % 12 +12;
	shared_ptr<DiZhi> pdz;
	switch(dzid)
	{
	case DZzi:
		//pdz = new DiZhi_Zi();
		pdz = make_shared<DiZhi_Zi>();
		break;
	case DZchou:
		pdz = make_shared<DiZhi_Chou>();
		break;
	case DZyin:
		pdz = make_shared<DiZhi_Yin>();
		break;
	case DZmao:
		pdz = make_shared<DiZhi_Mao>();
		break;
	case DZchen:
		pdz = make_shared<DiZhi_Chen>();
		break;
	case DZsi:
		pdz = make_shared<DiZhi_Si>();
		break;
	case DZwu:
		pdz = make_shared<DiZhi_Wu>();
		break;
	case DZwei:
		pdz = make_shared<DiZhi_Wei>();
		break;
	case DZshen:
		pdz = make_shared<DiZhi_Shen>();
		break;
	case DZyou:
		pdz = make_shared<DiZhi_You>();
		break;
	case DZxu:
		pdz = make_shared<DiZhi_Xu>();
		break;
	case DZhai:
		pdz = make_shared<DiZhi_Hai>();
		break;
	}

	return pdz;
}

shared_ptr<TianGan> Month::buildGan(int tgid)
{

	tgid = (tgid + 10) % 10;
	shared_ptr<TianGan> ptg;
	switch(tgid)
	{
	case TGjia:
		ptg = make_shared<TianGan_Jia>();
		break;
	case TGyi:
		ptg = make_shared<TianGan_Yi>();
		break;
	case TGbing:
		ptg = make_shared<TianGan_Bing>();
		break;
	case TGding:
		ptg = make_shared<TianGan_Ding>();
		break;
	case TGwu:
		ptg = make_shared<TianGan_Wu>();
		break;
	case TGji:
		ptg = make_shared<TianGan_Ji>();
		break;
	case TGgeng:
		ptg = make_shared<TianGan_Geng>();
		break;
	case TGxin:
		ptg = make_shared<TianGan_Xin>();
		break;
	case TGren:
		ptg = make_shared<TianGan_Ren>();
		break;
	case TGgui:
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
