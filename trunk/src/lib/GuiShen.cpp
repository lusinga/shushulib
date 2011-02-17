#include "GuiShen.h"
#include "Yin.h"
#include "Yang.h"

#include "Jin.h"
#include "Mu.h"
#include "Shui.h"
#include "Tu.h"
#include "Huo.h"

GuiShen::GuiShen(TianGan* pTG, bool isDay, DiZhi* pDiFen)
{
	int startForward=0;
	int startReverse=0;
	bool isForward;

	//¼×Îì¸ıÅ£Ñò
	if(pTG->getDzid() == TianGan::TGjia || pTG->getDzid() == TianGan::TGwu || pTG->getDzid() == TianGan::TGgeng)
	{
		startForward = DiZhi::DZchou;
		startReverse = DiZhi::DZwei;
		isForward = isDay;
	}
	//ÒÒÒÑÊóºïÏç
	else if(pTG->getDzid()==TianGan::TGyi || pTG->getDzid()==TianGan::TGji)
	{
		startForward = DiZhi::DZzi;
		startReverse = DiZhi::DZshen;
		isForward = isDay;				
	}
	//±û¶¡Öí¼¦Î»
	else if(pTG->getDzid()==TianGan::TGbing || pTG->getDzid()==TianGan::TGding)
	{
		startForward = DiZhi::DZhai;
		startReverse = DiZhi::DZyou;
		isForward = isDay;
	}
	//ÈÉ¹ïÉßÍÃ²Ø
	else if(pTG->getDzid()==TianGan::TGren || pTG->getDzid()==TianGan::TGgui)
	{
		startForward = DiZhi::DZsi;
		startReverse = DiZhi::DZmao;
		isForward = !isDay;
	}
	//ÁùĞÁ·êÂí»¢
	else if(pTG->getDzid()==TianGan::TGxin)
	{
		startForward = DiZhi::DZwu;
		startReverse = DiZhi::DZyin;
		isForward = !isDay;
	}
	//´ËÊÇ¹óÈË·½

	gsID = isForward ? (pDiFen->getDzid() - startForward) % 12 : (pDiFen->getDzid() + startForward) % 12;

	switch(gsID)
	{
	case 0:
		pName =new string("ÌìÒÒ¹óÉñ(ÒõÍÁ)");
		pYingYang = new Yin();
		pXing = new Tu();
		break;
	case 1:
		pName =new string("ÎŸÉß(Òõ»ğ)");
		pYingYang = new Yin();
		pXing = new Huo();
		break;
	case 2:
		pName =new string("ÖìÈ¸(Ñô»ğ)");
		pYingYang = new Yang();
		pXing = new Huo();
		break;
	case 3:
		pName =new string("ÁùºÏ(ÒõÄ¾)");
		pYingYang = new Yin();
		pXing = new Mu();
		break;
	case 4:
		pName =new string("¹´³Â(ÑôÍÁ)");
		pYingYang = new Yang();
		pXing = new Tu();
		break;
	case 5:
		pName =new string("ÇàÁú(ÑôÄ¾)");
		pYingYang = new Yang();
		pXing = new Mu();
		break;
	case 6:
		pName =new string("Ìì¿Õ(ÑôÍÁ)");
		pYingYang = new Yang();
		pXing = new Tu();
		break;
	case 7:
		pName =new string("°×»¢(Ñô½ğ)");
		pYingYang = new Yang();
		pXing = new Jin();
		break;
	case 8:
		pName =new string("Ì«³£(ÒõÍÁ)");
		pYingYang = new Yin();
		pXing = new Tu();
		break;
	case 9:
		pName =new string("ĞşÎä(ÑôË®)");
		pYingYang = new Yang();
		pXing = new Shui();
		break;
	case 10:
		pName =new string("Ì«Òõ(Òõ½ğ)");
		pYingYang = new Yin();
		pXing = new Jin();
		break;
	case 11:
		pName =new string("Ììºó(ÒõË®)");
		pYingYang = new Yin();
		pXing = new Shui();
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
	delete pYingYang;
	pYingYang = NULL;
}
