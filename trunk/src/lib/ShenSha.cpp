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
	case DiZhi::DZyin://Õı¶¡¶şÉê¸ı
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
	//case DiZhi::DZzi://×ÓËÈ³ó¸ıÖĞ
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
	//case DiZhi::DZyin://Õı¶¡¶şÉê¸ı
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
	case DiZhi::DZzi://×ÓËÈ³ó¸ıÖĞ
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
