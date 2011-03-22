#include "ShenSha.h"
#include "Month.h"
#include "Tiangan.h"

ShenSha::ShenSha(void)
{
}


ShenSha::~ShenSha(void)
{
}

bool ShenSha::isTianDe(DiZhi* pMonth, TianGan* pTG)
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

bool ShenSha::isTianDe(DiZhi* pMonth, DiZhi* pDZ)
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
}

bool ShenSha::isYueDe(DiZhi* pMonth, TianGan* pTG)
{
	int dzid = pMonth->getDzid();
	if(dzid == DiZhi::DZyin ||dzid == DiZhi::DZwu || dzid == DiZhi::DZmao)
	{
		return pTG->getTgid() == TianGan::TGbing;
	}
	else if(dzid == DiZhi::DZhai ||dzid == DiZhi::DZmao || dzid == DiZhi::DZwei)
	{
		return pTG->getTgid() == TianGan::TGjia;
	}
	else if(dzid == DiZhi::DZshen ||dzid == DiZhi::DZzi || dzid == DiZhi::DZchen)
	{
		return pTG->getTgid() == TianGan::TGren;
	}
	else if(dzid == DiZhi::DZsi ||dzid == DiZhi::DZyou || dzid == DiZhi::DZchou)
	{
		return pTG->getTgid() == TianGan::TGgeng;
	}
	else
		return false;
}
