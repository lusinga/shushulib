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

	//�����ţ��
	if(pTG->getDzid() == TianGan::TGjia || pTG->getDzid() == TianGan::TGwu || pTG->getDzid() == TianGan::TGgeng)
	{
		startForward = DiZhi::DZchou;
		startReverse = DiZhi::DZwei;
		isForward = isDay;
	}
	//���������
	else if(pTG->getDzid()==TianGan::TGyi || pTG->getDzid()==TianGan::TGji)
	{
		startForward = DiZhi::DZzi;
		startReverse = DiZhi::DZshen;
		isForward = isDay;				
	}
	//������λ
	else if(pTG->getDzid()==TianGan::TGbing || pTG->getDzid()==TianGan::TGding)
	{
		startForward = DiZhi::DZhai;
		startReverse = DiZhi::DZyou;
		isForward = isDay;
	}
	//�ɹ����ò�
	else if(pTG->getDzid()==TianGan::TGren || pTG->getDzid()==TianGan::TGgui)
	{
		startForward = DiZhi::DZsi;
		startReverse = DiZhi::DZmao;
		isForward = !isDay;
	}
	//��������
	else if(pTG->getDzid()==TianGan::TGxin)
	{
		startForward = DiZhi::DZwu;
		startReverse = DiZhi::DZyin;
		isForward = !isDay;
	}
	//���ǹ��˷�

	gsID = isForward ? (pDiFen->getDzid() - startForward) % 12 : (pDiFen->getDzid() + startForward) % 12;

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
	delete pXing;
	pXing = NULL;
	delete pYingYang;
	pYingYang = NULL;
}
