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

GuiShen::GuiShen(boost::shared_ptr<TianGan> pTG, bool isDay, boost::shared_ptr<DiZhi> pDiFen)
{
	int startForward=0;
	int startReverse=0;
	bool isForward=true;

	//�����ţ��
	if(pTG->getTgid() == TGjia || pTG->getTgid() == TGwu || pTG->getTgid() == TGgeng)
	{
		startForward = DZchou;
		startReverse = DZwei;
		isForward = isDay;
	}
	//���������
	else if(pTG->getTgid()==TGyi || pTG->getTgid()==TGji)
	{
		startForward = DZzi;
		startReverse = DZshen;
		isForward = isDay;
	}
	//������λ
	else if(pTG->getTgid()==TGbing || pTG->getTgid()==TGding)
	{
		startForward = DZhai;
		startReverse = DZyou;
		isForward = isDay;
	}
	//�ɹ����ò�
	else if(pTG->getTgid()==TGren || pTG->getTgid()==TGgui)
	{
		startForward = DZsi;
		startReverse = DZmao;
		isForward = !isDay;
	}
	//��������
	else if(pTG->getTgid()==TGxin)
	{
		startForward = DZwu;
		startReverse = DZyin;
		isForward = !isDay;
	}
	//���ǹ��˷�
	else{
		cout<<"Error! ��ɴ���"<<endl;
	}

	gsID = isForward ? (pDiFen->getDzid() - startForward + 12) % 12 : (pDiFen->getDzid() + startReverse + 12) % 12;

	switch(gsID)
	{
	case 0:
		pName = boost::make_shared<string>("�� (���ҹ��� ����)");
		pYinYang = boost::make_shared<Yin>();
		pXing = boost::make_shared<Tu>();
		pDZ = Month::buildZhi(DZchou);
		break;
	case 1:
		pName = boost::make_shared<string>("�� (Ο�� ����)");
		pDZ = Month::buildZhi(DZsi);
		pYinYang = boost::make_shared<Yin>();
		pXing = boost::make_shared<Huo>();
		break;
	case 2:
		pName =boost::make_shared<string>("�� (��ȸ ����)");
		pDZ = Month::buildZhi(DZwu);
		pYinYang = boost::make_shared<Yang>();
		pXing = boost::make_shared<Huo>();
		break;
	case 3:
		pName =boost::make_shared<string>("î (���� ��ľ)");
		pDZ = Month::buildZhi(DZmao);
		pYinYang = boost::make_shared<Yin>();
		pXing = boost::make_shared<Mu>();
		break;
	case 4:
		pName =boost::make_shared<string>("�� (���� ����)");
		pDZ = Month::buildZhi(DZchen);
		pYinYang = boost::make_shared<Yang>();
		pXing = boost::make_shared<Tu>();
		break;
	case 5:
		pName =boost::make_shared<string>("�� (���� ��ľ)");
		pDZ = Month::buildZhi(DZyin);
		pYinYang = boost::make_shared<Yang>();
		pXing = boost::make_shared<Mu>();
		break;
	case 6:
		pName =boost::make_shared<string>("�� (��� ����)");
		pDZ = Month::buildZhi(DZxu);
		pYinYang = boost::make_shared<Yang>();
		pXing = boost::make_shared<Tu>();
		break;
	case 7:
		pName =boost::make_shared<string>("�� (�׻� ����)");
		pDZ = Month::buildZhi(DZshen);
		pYinYang = boost::make_shared<Yang>();
		pXing = boost::make_shared<Jin>();
		break;
	case 8:
		pName =boost::make_shared<string>("δ (̫�� ����)");
		pDZ = Month::buildZhi(DZwei);
		pYinYang = boost::make_shared<Yin>();
		pXing = boost::make_shared<Tu>();
		break;
	case 9:
		pName =boost::make_shared<string>("�� (���� ��ˮ)");
		pDZ = Month::buildZhi(DZzi);
		pYinYang = boost::make_shared<Yang>();
		pXing = boost::make_shared<Shui>();
		break;
	case 10:
		pName =boost::make_shared<string>("�� (̫�� ����)");
		pDZ = Month::buildZhi(DZyou);
		pYinYang = boost::make_shared<Yin>();
		pXing = boost::make_shared<Jin>();
		break;
	case 11:
		pName =boost::make_shared<string>("�� (�����ˮ)");
		pDZ = Month::buildZhi(DZhai);
		pYinYang = boost::make_shared<Yin>();
		pXing = boost::make_shared<Shui>();
		break;
	default:
		pName = boost::make_shared<string>("����");
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
