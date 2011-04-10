#include "GuiShen.h"
#include "Yin.h"
#include "Yang.h"

#include "Jin.h"
#include "Mu.h"
#include "Shui.h"
#include "Tu.h"
#include "Huo.h"
#include "Month.h"

#include <boost/make_shared.hpp>

using boost::make_shared;

GuiShen::GuiShen(shared_ptr<TianGan> pTG, bool isDay, shared_ptr<DiZhi> pDiFen)
{
	int startForward=0;
	int startReverse=0;
	bool isForward=true;

	//¼×Îì¸ıÅ£Ñò
	if(pTG->getTgid() == TianGan::TGjia || pTG->getTgid() == TianGan::TGwu || pTG->getTgid() == TianGan::TGgeng)
	{
		startForward = DiZhi::DZchou;
		startReverse = DiZhi::DZwei;
		isForward = isDay;
	}
	//ÒÒÒÑÊóºïÏç
	else if(pTG->getTgid()==TianGan::TGyi || pTG->getTgid()==TianGan::TGji)
	{
		startForward = DiZhi::DZzi;
		startReverse = DiZhi::DZshen;
		isForward = isDay;				
	}
	//±û¶¡Öí¼¦Î»
	else if(pTG->getTgid()==TianGan::TGbing || pTG->getTgid()==TianGan::TGding)
	{
		startForward = DiZhi::DZhai;
		startReverse = DiZhi::DZyou;
		isForward = isDay;
	}
	//ÈÉ¹ïÉßÍÃ²Ø
	else if(pTG->getTgid()==TianGan::TGren || pTG->getTgid()==TianGan::TGgui)
	{
		startForward = DiZhi::DZsi;
		startReverse = DiZhi::DZmao;
		isForward = !isDay;
	}
	//ÁùĞÁ·êÂí»¢
	else if(pTG->getTgid()==TianGan::TGxin)
	{
		startForward = DiZhi::DZwu;
		startReverse = DiZhi::DZyin;
		isForward = !isDay;
	}
	//´ËÊÇ¹óÈË·½
	else{
		cout<<"Error! Ìì¸É´íÎó£¡"<<endl;
	}
	
	gsID = isForward ? (pDiFen->getDzid() - startForward + 12) % 12 : (pDiFen->getDzid() + startReverse + 12) % 12;
	
	switch(gsID)
	{
	case 0:
		pName = make_shared<string>("³ó (ÌìÒÒ¹óÉñ ÒõÍÁ)");
		pYinYang = make_shared<Yin>();
		pXing = make_shared<Tu>();
		pDZ = Month::buildZhi(DiZhi::DZchou);
		break;
	case 1:
		pName = make_shared<string>("ËÈ (ÎŸÉß Òõ»ğ)");
		pDZ = Month::buildZhi(DiZhi::DZsi);
		pYinYang = make_shared<Yin>();
		pXing = make_shared<Huo>();
		break;
	case 2:
		pName =make_shared<string>("Îç (ÖìÈ¸ Ñô»ğ)");
		pDZ = Month::buildZhi(DiZhi::DZwu);
		pYinYang = make_shared<Yang>();
		pXing = make_shared<Huo>();
		break;
	case 3:
		pName =make_shared<string>("Ã® (ÁùºÏ ÒõÄ¾)");
		pDZ = Month::buildZhi(DiZhi::DZmao);
		pYinYang = make_shared<Yin>();
		pXing = make_shared<Mu>();
		break;
	case 4:
		pName =make_shared<string>("³½ (¹´³Â ÑôÍÁ)");
		pDZ = Month::buildZhi(DiZhi::DZchen);
		pYinYang = make_shared<Yang>();
		pXing = make_shared<Tu>();
		break;
	case 5:
		pName =make_shared<string>("Òú (ÇàÁú ÑôÄ¾)");
		pDZ = Month::buildZhi(DiZhi::DZyin);
		pYinYang = make_shared<Yang>();
		pXing = make_shared<Mu>();
		break;
	case 6:
		pName =make_shared<string>("Ğç (Ìì¿Õ ÑôÍÁ)");
		pDZ = Month::buildZhi(DiZhi::DZxu);
		pYinYang = make_shared<Yang>();
		pXing = make_shared<Tu>();
		break;
	case 7:
		pName =make_shared<string>("Éê (°×»¢ Ñô½ğ)");
		pDZ = Month::buildZhi(DiZhi::DZshen);
		pYinYang = make_shared<Yang>();
		pXing = make_shared<Jin>();
		break;
	case 8:
		pName =make_shared<string>("Î´ (Ì«³£ ÒõÍÁ)");
		pDZ = Month::buildZhi(DiZhi::DZwei);
		pYinYang = make_shared<Yin>();
		pXing = make_shared<Tu>();
		break;
	case 9:
		pName =make_shared<string>("×Ó (ĞşÎä ÑôË®)");
		pDZ = Month::buildZhi(DiZhi::DZzi);
		pYinYang = make_shared<Yang>();
		pXing = make_shared<Shui>();
		break;
	case 10:
		pName =make_shared<string>("ÓÏ (Ì«Òõ Òõ½ğ)");
		pDZ = Month::buildZhi(DiZhi::DZyou);
		pYinYang = make_shared<Yin>();
		pXing = make_shared<Jin>();
		break;
	case 11:
		pName =make_shared<string>("º¥ (ÌìºóÒõË®)");
		pDZ = Month::buildZhi(DiZhi::DZhai);
		pYinYang = make_shared<Yin>();
		pXing = make_shared<Shui>();
		break;
	default:
		pName = make_shared<string>("´íÎó£¡");
		break;
	}
}

string GuiShen::getName()
{
	return *pName;
}

GuiShen::~GuiShen(void)
{

}
