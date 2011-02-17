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
	bool isForward=true;

	//º◊ŒÏ∏˝≈£—Ú
	if(pTG->getTgid() == TianGan::TGjia || pTG->getTgid() == TianGan::TGwu || pTG->getTgid() == TianGan::TGgeng)
	{
		startForward = DiZhi::DZchou;
		startReverse = DiZhi::DZwei;
		isForward = isDay;
	}
	//“““— Û∫ÔœÁ
	else if(pTG->getTgid()==TianGan::TGyi || pTG->getTgid()==TianGan::TGji)
	{
		startForward = DiZhi::DZzi;
		startReverse = DiZhi::DZshen;
		isForward = isDay;				
	}
	//±˚∂°÷Ìº¶Œª
	else if(pTG->getTgid()==TianGan::TGbing || pTG->getTgid()==TianGan::TGding)
	{
		startForward = DiZhi::DZhai;
		startReverse = DiZhi::DZyou;
		isForward = isDay;
	}
	//»…πÔ…ﬂÕ√≤ÿ
	else if(pTG->getTgid()==TianGan::TGren || pTG->getTgid()==TianGan::TGgui)
	{
		startForward = DiZhi::DZsi;
		startReverse = DiZhi::DZmao;
		isForward = !isDay;
	}
	//¡˘–¡∑Í¬Ìª¢
	else if(pTG->getTgid()==TianGan::TGxin)
	{
		startForward = DiZhi::DZwu;
		startReverse = DiZhi::DZyin;
		isForward = !isDay;
	}
	//¥À «πÛ»À∑Ω
	else{
		cout<<"Error! ÃÏ∏…¥ÌŒÛ£°"<<endl;
	}
	
	gsID = isForward ? (pDiFen->getDzid() - startForward + 12) % 12 : (pDiFen->getDzid() + startForward + 12) % 12;
	cout<<"[debug]gsID="<<gsID<<endl;

	switch(gsID)
	{
	case 0:
		pName =new string("ÃÏ““πÛ…Ò(“ıÕ¡)");
		pYingYang = new Yin();
		pXing = new Tu();
		break;
	case 1:
		pName =new string("Œü…ﬂ(“ıª)");
		pYingYang = new Yin();
		pXing = new Huo();
		break;
	case 2:
		pName =new string("÷Ï»∏(—Ùª)");
		pYingYang = new Yang();
		pXing = new Huo();
		break;
	case 3:
		pName =new string("¡˘∫œ(“ıƒæ)");
		pYingYang = new Yin();
		pXing = new Mu();
		break;
	case 4:
		pName =new string("π¥≥¬(—ÙÕ¡)");
		pYingYang = new Yang();
		pXing = new Tu();
		break;
	case 5:
		pName =new string("«‡¡˙(—Ùƒæ)");
		pYingYang = new Yang();
		pXing = new Mu();
		break;
	case 6:
		pName =new string("ÃÏø’(—ÙÕ¡)");
		pYingYang = new Yang();
		pXing = new Tu();
		break;
	case 7:
		pName =new string("∞◊ª¢(—ÙΩ)");
		pYingYang = new Yang();
		pXing = new Jin();
		break;
	case 8:
		pName =new string("Ã´≥£(“ıÕ¡)");
		pYingYang = new Yin();
		pXing = new Tu();
		break;
	case 9:
		pName =new string("–˛Œ‰(—ÙÀÆ)");
		pYingYang = new Yang();
		pXing = new Shui();
		break;
	case 10:
		pName =new string("Ã´“ı(“ıΩ)");
		pYingYang = new Yin();
		pXing = new Jin();
		break;
	case 11:
		pName =new string("ÃÏ∫Û(“ıÀÆ)");
		pYingYang = new Yin();
		pXing = new Shui();
		break;
	default:
		pName = new string("¥ÌŒÛ£°");
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
