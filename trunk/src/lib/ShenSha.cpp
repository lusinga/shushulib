#include "ShenSha.h"
#include "Month.h"
#include "Tiangan.h"

ShenSha::ShenSha(void)
{
}


ShenSha::~ShenSha(void)
{
}

bool ShenSha::isTianDe(boost::shared_ptr<DiZhi> pMonth, boost::shared_ptr<TianGan> pTG)
{
	switch (pMonth->getDzid())
	{
	case DZyin://正丁二申庚
		return pTG->getTgid() == TGding;
		break;
	//case DZmao://2
	//	//return pDZ(DZshen);
	//	break;
	case DZchen://3
		return pTG->getTgid() == TGren;
		break;
	case DZsi://4
		return pTG->getTgid() ==TGxin;
		break;
	//case DZwu://5
	//	//return Month::buildZhi(DZhai);
	//	break;
	case DZwei://6
		return pTG->getTgid() == TGjia;
		break;
	case DZshen://7
		return pTG->getTgid() == TGgui;
		break;
	//case DZyou://8
	//	//return Month::buildZhi(DZyin);
	//	break;
	case DZxu://9
		return pTG->getTgid() == TGbing;
		break;
	case DZhai://10
		return pTG->getTgid() == TGyi;
		break;
	//case DZzi://子巳丑庚中
	//	return //Month::buildZhi(DZsi);
	//	break;
	case DZchou:
		return pTG->getTgid() == TGgeng;
		break;
	default:
		return false;
		break;
	}
}

bool ShenSha::isTianDe(boost::shared_ptr<DiZhi>  pMonth, boost::shared_ptr<DiZhi>  pDZ)
{
	switch (pMonth->getDzid())
	{
	//case DZyin://正丁二申庚
	//	return pTG->getTgid() == TianGan::TGding;
	//	break;
	case DZmao://2
		return pDZ->getDzid() == (DZshen);
		break;
	//case DZchen://3
	//	//return pTG->getTgid() == TianGan::TGren;
	//	break;
	//case DZsi://4
	//	//return pTG->getTgid() ==(TianGan::TGxin);
	//	break;
	case DZwu://5
		return pDZ->getDzid() == (DZhai);
		break;
	case DZwei://6
		//return pTG->getTgid() == (TianGan::TGjia);
		break;
	//case DZshen://7
	//	//return pTG->getTgid() == (TianGan::TGgui);
	//	break;
	case DZyou://8
		return pDZ->getDzid() == (DZyin);
		break;
	//case DZxu://9
	//	//return pTG->getTgid() == (TianGan::TGbing);
	//	break;
	//case DZhai://10
	//	//return pTG->getTgid() == (TianGan::TGyi);
	//	break;
	case DZzi://子巳丑庚中
		return pDZ->getDzid() == (DZsi);
		break;
	//case DZchou:
	//	//return pTG->getTgid() == (TianGan::TGgeng);
	//	break;
	default:
		return false;
		break;
	}

	return false;
}

bool ShenSha::isYueDe(boost::shared_ptr<DiZhi>  pMonth, int tgid)
{
	int dzid = pMonth->getDzid();
	if(dzid == DZyin ||dzid == DZwu || dzid == DZmao)
	{
		return tgid == TGbing;
	}
	else if(dzid == DZhai ||dzid == DZmao || dzid == DZwei)
	{
		return tgid == TGjia;
	}
	else if(dzid == DZshen ||dzid == DZzi || dzid == DZchen)
	{
		return tgid == TGren;
	}
	else if(dzid == DZsi ||dzid == DZyou || dzid == DZchou)
	{
		return tgid == TGgeng;
	}
	else
		return false;
}

bool ShenSha::isTianDeHe(boost::shared_ptr<DiZhi>  pMonth, boost::shared_ptr<TianGan> pTG)
{
	int tgid = pTG->getTgid();

	switch(pMonth->getMonth())
	{
	case 1:
		return tgid == TGren;
		break;
	case 2:
		return tgid == TGyi;
		break;
	case 3:
		return tgid == TGding;
		break;
	case 4:
		return tgid == TGbing;
		break;
	case 5:
		return tgid == TGwu;
		break;
	case 6:
		return tgid == TGji;
		break;
	case 7:
		return tgid == TGwu;
		break;
	case 8:
		return tgid == TGji;
		break;
	case 9:
		return tgid == TGxin;
		break;
	case 10:
		return tgid == TGgeng;
		break;
	case 11:
		return tgid == TGren;
		break;
	case 12:
		return tgid == TGyi;
		break;
	default:
		return false;
		break;
	}
}

bool ShenSha::isTianMa(int month, int dzid)
{
	switch(month % 6)
	{
	case 1:
		return dzid == DZwu;
		break;
	case 2:
		return dzid == DZshen;
		break;
	case 3:
		return dzid == DZxu;
		break;
	case 4:
		return dzid == DZzi;
		break;
	case 5:
		return dzid == DZyin;
		break;
	case 0:
		return dzid == DZchen;
		break;
	default:
		return false;
		break;
	}
}

bool ShenSha::isDuoMa(int day_dzid, int dzid)
{
	switch (day_dzid)
	{
	case DZshen:
	case DZzi:
	case DZchen:
		return dzid == DZyin;
		break;
	case DZhai:
	case DZmao:
	case DZwei:
		return dzid == DZsi;
		break;
	case DZyin:
	case DZwu:
	case DZxu:
		return dzid == DZshen;
		break;
	case DZsi:
	case DZyou:
	case DZchou:
		return dzid == DZhai;
		break;
	default:
		return false;
	}
}

bool ShenSha::isJieSha(int day_dzid, int dzid)
{
	switch (day_dzid)
	{
	case DZshen:
	case DZzi:
	case DZchen:
		return dzid == DZsi;
		break;
	case DZhai:
	case DZmao:
	case DZwei:
		return dzid == DZhai;
		break;
	case DZyin:
	case DZwu:
	case DZxu:
		return dzid == DZshen;
		break;
	case DZsi:
	case DZyou:
	case DZchou:
		return dzid == DZyin;
		break;
	default:
		return false;
	}
}

