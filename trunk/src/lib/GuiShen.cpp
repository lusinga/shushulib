#include "GuiShen.h"
#include "Yin.h"
#include "Yang.h"

#include "Jin.h"
#include "Mu.h"
#include "Shui.h"
#include "Tu.h"
#include "Huo.h"

GuiShen::GuiShen(TianGan* pTG, bool isDay)
{
	//�����ţ��
	if(pTG->getDzid() == TianGan::TGjia || pTG->getDzid() == TianGan::TGwu || pTG->getDzid() == TianGan::TGgeng)
	{
		if(isDay)
		{
			
		}
		else
		{

		}
	}

	switch(gsID)
	{
	case 0:
		pName =new string("���ҹ���(����)");
		pYingYang = new Yin();
		pXing = new Tu();
		break;
	case 1:
		pName =new string("Ο��(����)");
		pYingYang = new Yin();
		pXing = new Huo();
		break;
	case 2:
		pName =new string("��ȸ(����)");
		pYingYang = new Yang();
		pXing = new Huo();
		break;
	case 3:
		pName =new string("����(��ľ)");
		pYingYang = new Yin();
		pXing = new Mu();
		break;
	case 4:
		pName =new string("����(����)");
		pYingYang = new Yang();
		pXing = new Tu();
		break;
	case 5:
		pName =new string("����(��ľ)");
		pYingYang = new Yang();
		pXing = new Mu();
		break;
	case 6:
		pName =new string("���(����)");
		pYingYang = new Yang();
		pXing = new Tu();
		break;
	case 7:
		pName =new string("�׻�(����)");
		pYingYang = new Yang();
		pXing = new Jin();
		break;
	case 8:
		pName =new string("̫��(����)");
		pYingYang = new Yin();
		pXing = new Tu();
		break;
	case 9:
		pName =new string("����(��ˮ)");
		pYingYang = new Yang();
		pXing = new Shui();
		break;
	case 10:
		pName =new string("̫��(����)");
		pYingYang = new Yin();
		pXing = new Jin();
		break;
	case 11:
		pName =new string("���(��ˮ)");
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
}
