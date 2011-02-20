#include "GuiShen.h"
#include "Yin.h"
#include "Yang.h"

#include "Jin.h"
#include "Mu.h"
#include "Shui.h"
#include "Tu.h"
#include "Huo.h"
#include "Month.h"

GuiShen::GuiShen(TianGan* pTG, bool isDay, DiZhi* pDiFen)
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
		pName =new string("³ó (ÌìÒÒ¹óÉñ ÒõÍÁ)");
		pYinYang = new Yin();
		pXing = new Tu();
		pGod = Month::buildZhi(DiZhi::DZchou);
		break;
	case 1:
		pName =new string("ËÈ (ÎŸÉß Òõ»ğ)");
		pGod = Month::buildZhi(DiZhi::DZsi);
		pYinYang = new Yin();
		pXing = new Huo();
		break;
	case 2:
		pName =new string("Îç (ÖìÈ¸ Ñô»ğ)");
		pGod = Month::buildZhi(DiZhi::DZwu);
		pYinYang = new Yang();
		pXing = new Huo();
		break;
	case 3:
		pName =new string("Ã® (ÁùºÏ ÒõÄ¾)");
		pGod = Month::buildZhi(DiZhi::DZmao);
		pYinYang = new Yin();
		pXing = new Mu();
		break;
	case 4:
		pName =new string("³½ (¹´³Â ÑôÍÁ)");
		pGod = Month::buildZhi(DiZhi::DZchen);
		pYinYang = new Yang();
		pXing = new Tu();
		break;
	case 5:
		pName =new string("Òú (ÇàÁú ÑôÄ¾)");
		pGod = Month::buildZhi(DiZhi::DZyin);
		pYinYang = new Yang();
		pXing = new Mu();
		break;
	case 6:
		pName =new string("Ğç (Ìì¿Õ ÑôÍÁ)");
		pGod = Month::buildZhi(DiZhi::DZxu);
		pYinYang = new Yang();
		pXing = new Tu();
		break;
	case 7:
		pName =new string("Éê (°×»¢ Ñô½ğ)");
		pGod = Month::buildZhi(DiZhi::DZshen);
		pYinYang = new Yang();
		pXing = new Jin();
		break;
	case 8:
		pName =new string("Î´ (Ì«³£ ÒõÍÁ)");
		pGod = Month::buildZhi(DiZhi::DZwei);
		pYinYang = new Yin();
		pXing = new Tu();
		break;
	case 9:
		pName =new string("×Ó (ĞşÎä ÑôË®)");
		pGod = Month::buildZhi(DiZhi::DZzi);
		pYinYang = new Yang();
		pXing = new Shui();
		break;
	case 10:
		pName =new string("ÓÏ (Ì«Òõ Òõ½ğ)");
		pGod = Month::buildZhi(DiZhi::DZyou);
		pYinYang = new Yin();
		pXing = new Jin();
		break;
	case 11:
		pName =new string("º¥ (ÌìºóÒõË®)");
		pGod = Month::buildZhi(DiZhi::DZhai);
		pYinYang = new Yin();
		pXing = new Shui();
		break;
	default:
		pName = new string("´íÎó£¡");
		break;
	}
}

string GuiShen::getName()
{
	return *pName;
}

GuiShen::~GuiShen(void)
{
	delete pName;
	pName = NULL;
	delete pXing;
	pXing = NULL;
	delete pYinYang;
	pYinYang = NULL;
}
