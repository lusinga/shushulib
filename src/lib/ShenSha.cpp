#include "ShenSha.h"
#include "Month.h"
#include "Tiangan.h"

ShenSha::ShenSha(void)
{
}


ShenSha::~ShenSha(void)
{
}

bool ShenSha::isTianDe(shared_ptr<DiZhi> pMonth, shared_ptr<TianGan> pTG)
{
	switch (pMonth->getDzid())
	{
	case DiZhi::DZyin://正丁二申庚
		return pTG->getTgid() == TianGan::TGding;
		break;
	//case DiZhi::DZmao://2
	//	//return pDZ(DiZhi::DZshen);
	//	break;
	case DiZhi::DZchen://3
		return pTG->getTgid() == TianGan::TGren;
		break;
	case DiZhi::DZsi://4
		return pTG->getTgid() ==(TianGan::TGxin);
		break;
	//case DiZhi::DZwu://5
	//	//return Month::buildZhi(DiZhi::DZhai);
	//	break;
	case DiZhi::DZwei://6
		return pTG->getTgid() == (TianGan::TGjia);
		break;
	case DiZhi::DZshen://7
		return pTG->getTgid() == (TianGan::TGgui);
		break;
	//case DiZhi::DZyou://8
	//	//return Month::buildZhi(DiZhi::DZyin);
	//	break;
	case DiZhi::DZxu://9
		return pTG->getTgid() == (TianGan::TGbing);
		break;
	case DiZhi::DZhai://10
		return pTG->getTgid() == (TianGan::TGyi);
		break;
	//case DiZhi::DZzi://子巳丑庚中
	//	return //Month::buildZhi(DiZhi::DZsi);
	//	break;
	case DiZhi::DZchou:
		return pTG->getTgid() == (TianGan::TGgeng);
		break;
	default:
		return false;
		break;
	}
}

bool ShenSha::isTianDe(shared_ptr<DiZhi>  pMonth, shared_ptr<DiZhi>  pDZ)
{
	switch (pMonth->getDzid())
	{
	//case DiZhi::DZyin://正丁二申庚
	//	return pTG->getTgid() == TianGan::TGding;
	//	break;
	case DiZhi::DZmao://2
		return pDZ->getDzid() == (DiZhi::DZshen);
		break;
	//case DiZhi::DZchen://3
	//	//return pTG->getTgid() == TianGan::TGren;
	//	break;
	//case DiZhi::DZsi://4
	//	//return pTG->getTgid() ==(TianGan::TGxin);
	//	break;
	case DiZhi::DZwu://5
		return pDZ->getDzid() == (DiZhi::DZhai);
		break;
	case DiZhi::DZwei://6
		//return pTG->getTgid() == (TianGan::TGjia);
		break;
	//case DiZhi::DZshen://7
	//	//return pTG->getTgid() == (TianGan::TGgui);
	//	break;
	case DiZhi::DZyou://8
		return pDZ->getDzid() == (DiZhi::DZyin);
		break;
	//case DiZhi::DZxu://9
	//	//return pTG->getTgid() == (TianGan::TGbing);
	//	break;
	//case DiZhi::DZhai://10
	//	//return pTG->getTgid() == (TianGan::TGyi);
	//	break;
	case DiZhi::DZzi://子巳丑庚中
		return pDZ->getDzid() == (DiZhi::DZsi);
		break;
	//case DiZhi::DZchou:
	//	//return pTG->getTgid() == (TianGan::TGgeng);
	//	break;
	default:
		return false;
		break;
	}

	return false;
}

bool ShenSha::isYueDe(shared_ptr<DiZhi>  pMonth, int tgid)
{
	int dzid = pMonth->getDzid();
	if(dzid == DiZhi::DZyin ||dzid == DiZhi::DZwu || dzid == DiZhi::DZmao)
	{
		return tgid == TianGan::TGbing;
	}
	else if(dzid == DiZhi::DZhai ||dzid == DiZhi::DZmao || dzid == DiZhi::DZwei)
	{
		return tgid == TianGan::TGjia;
	}
	else if(dzid == DiZhi::DZshen ||dzid == DiZhi::DZzi || dzid == DiZhi::DZchen)
	{
		return tgid == TianGan::TGren;
	}
	else if(dzid == DiZhi::DZsi ||dzid == DiZhi::DZyou || dzid == DiZhi::DZchou)
	{
		return tgid == TianGan::TGgeng;
	}
	else
		return false;
}

bool ShenSha::isTianDeHe(shared_ptr<DiZhi>  pMonth, shared_ptr<TianGan> pTG)
{
	int tgid = pTG->getTgid();

	switch(pMonth->getMonth())
	{
	case 1:
		return tgid == TianGan::TGren; 
		break;
	case 2:
		return tgid == TianGan::TGyi;
		break;
	case 3:
		return tgid == TianGan::TGding;
		break;
	case 4:
		return tgid == TianGan::TGbing;
		break;
	case 5:
		return tgid == TianGan::TGwu;
		break;
	case 6:
		return tgid == TianGan::TGji;
		break;
	case 7:
		return tgid == TianGan::TGwu;
		break;
	case 8:
		return tgid == TianGan::TGji;
		break;
	case 9:
		return tgid == TianGan::TGxin;
		break;
	case 10:
		return tgid == TianGan::TGgeng;
		break;
	case 11:
		return tgid == TianGan::TGren;
		break;
	case 12:
		return tgid == TianGan::TGyi;
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
		return dzid == DiZhi::DZwu;
		break;
	case 2:
		return dzid == DiZhi::DZshen;
		break;
	case 3:
		return dzid == DiZhi::DZxu;
		break;
	case 4:
		return dzid == DiZhi::DZzi;
		break;
	case 5:
		return dzid == DiZhi::DZyin;
		break;
	case 0:
		return dzid == DiZhi::DZchen;
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
	case DiZhi::DZshen:
	case DiZhi::DZzi:
	case DiZhi::DZchen:
		return dzid == DiZhi::DZyin;
		break;
	case DiZhi::DZhai:
	case DiZhi::DZmao:
	case DiZhi::DZwei:
		return dzid == DiZhi::DZsi;
		break;
	case DiZhi::DZyin:
	case DiZhi::DZwu:
	case DiZhi::DZxu:
		return dzid == DiZhi::DZshen;
		break;
	case DiZhi::DZsi:
	case DiZhi::DZyou:
	case DiZhi::DZchou:
		return dzid == DiZhi::DZhai;
		break;
	default:
		return false;
	}
}

bool ShenSha::isJieSha(int day_dzid, int dzid)
{
	switch (day_dzid)
	{
	case DiZhi::DZshen:
	case DiZhi::DZzi:
	case DiZhi::DZchen:
		return dzid == DiZhi::DZsi;
		break;
	case DiZhi::DZhai:
	case DiZhi::DZmao:
	case DiZhi::DZwei:
		return dzid == DiZhi::DZhai;
		break;
	case DiZhi::DZyin:
	case DiZhi::DZwu:
	case DiZhi::DZxu:
		return dzid == DiZhi::DZshen;
		break;
	case DiZhi::DZsi:
	case DiZhi::DZyou:
	case DiZhi::DZchou:
		return dzid == DiZhi::DZyin;
		break;
	default:
		return false;
	}
}

