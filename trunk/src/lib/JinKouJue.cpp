#include "JinKouJue.h"
#include "Month.h"
#include "Ganzhi.h"

#include <iostream>
using namespace std;

JinKouJue::JinKouJue(Gan_Zhi* pYear,Gan_Zhi* pMonth,Gan_Zhi* pDay,Gan_Zhi* pHour,DiZhi* pDiFen)
{
	this->pYear = pYear;
	this->pMonth = pMonth;
	this->pDay = pDay;
	this->pHour = pHour;
	this->pDiFen = pDiFen;

	this->pYueJiang = Month::buildZhi(Month::getYueJiang(this->pMonth->pDZ)-this->pHour->pDZ->getDzid()+this->pDiFen->getDzid());

	bool isDay = pHour->pDZ->getDzid()<DiZhi::DZyou && pHour->pDZ->getDzid()>=DiZhi::DZmao;

	//cout<<"[debug]isDay="<<isDay<<endl;

	this->pGuiShen = new GuiShen(pDay->pTG,isDay,pDiFen);

	pRenYuan = Month::wuZiYuanDu(pDay->pTG,pDiFen);
}

JinKouJue::~JinKouJue(void)
{
}

void JinKouJue::show()
{
	cout<<this->pYear->getName()<<"��"<<this->pMonth->getName()<<"��"<<this->pDay->getName()<<"��"<<this->pHour->getName()<<"ʱ"<<endl;
	cout<<"��Ԫ��"<<this->pRenYuan->getName()<<endl;
	cout<<"����"<<Month::wuZiYuanDu(pDay->pTG,this->pGuiShen->pGod)->getName()<<this->pGuiShen->getName()<<endl;
	cout<<"�½���"<<Month::wuZiYuanDu(pDay->pTG,this->pYueJiang)->getName()<<this->pYueJiang->getName()<<"("<<parseYueJiangName()<<")"<<endl;
	cout<<"�ط֣�"<<this->pDiFen->getName()<<endl;

	duanKe();

	cout<<"=================================================="<<endl;
}

string JinKouJue::parseYueJiangName()
{
	string name[] = {"����","�ӿ�","�ӿ�","����","С��","ʤ��","̫��","���","̫��","����","��","���"};
	return name[11-this->pYueJiang->getDzid()];
}

void JinKouJue::duanKe()
{
	int iYang = 0;
	if(this->pRenYuan->getTgid() % 2 == 0) 
		iYang++;
	if(this->pGuiShen->pYinYang->isYang()) 
		iYang++;
	if(this->pYueJiang->getDzid() % 2 == 0)
		iYang++;
	if(this->pDiFen->getDzid() % 2 == 0)
		iYang++;
	
	switch(iYang)
	{
	case 0:
		cout<<"�����������Խ�Ϊ�ã������������ؿ�ʼ�򹫿���չ����������Ů��ת�����ӻ�������ת��Ů�ӣ����忪ʼ�����������ط�չ�����²��ɲ�֮������"<<endl;
		bYongShenIsJiang = true;
		break;
	case 1:
		cout<<"����Ϊ�ã��������С������������淽��չ��ǰ;������"<<endl;
		if (this->pYueJiang->getDzid() % 2 == 0)
		{
			//��������������Ϊ�ü��Խ�Ϊ�á�
			bYongShenIsJiang = true;
		}
		else
		{
			bYongShenIsJiang = false;
		}
		break;
	case 2:
		cout<<"�����������Խ�Ϊ�ã����ﻹ��̫���ʻ������¼���Ů���������ײ���������λ��Ͼ��ϡ�"<<endl;
		bYongShenIsJiang = false;
		break;
	case 3:
		cout<<"����Ϊ�ã�������Ů���������򷴷���չ��ǰ;������"<<endl;
		if (this->pYueJiang->getDzid() % 2 != 0)
		{
			//��������������Ϊ�ü��Խ�Ϊ�á�
			bYongShenIsJiang = true;
		}
		else
		{
			bYongShenIsJiang = false;
		}
		break;
	case 4:
		cout<<"��������������Ϊ�á���λ��������������������ת˥�����忪ʼ�������ķ��棬�������ؿ�ʼ���ӣ����忪ʼ���ɣ�����תΪŮ������ŮתΪ�С��紦��ɽ�Ķ��壬���·�չ���ڱ�Ȼ�����������ٲ��׳١�"<<endl;
		bYongShenIsJiang = false;
		break;
	default:
		cout<<"���������ˡ�"<<endl;
		break;
	}

	Xing** pXings = new Xing*[4];
	//�ˣ����£���
	pXings[0] = pRenYuan->buildXing();
	pXings[1] = pGuiShen->pXing;
	pXings[2] = pYueJiang->buildXing();
	pXings[3] = pDiFen->buildXing();

	Xing* pYongShenXing = bYongShenIsJiang? pXings[2] : pXings[1];

	int state = Xing::getState(pYongShenXing,pXings,4);
	switch(state)
	{
	case Xing::WANG:
		cout<<"������"<<endl;
		break;
	case Xing::XIANG:
		cout<<"������"<<endl;
		break;
	case Xing::XIU:
		cout<<"������"<<endl;
		break;
	case Xing::QIU:
		cout<<"������"<<endl;
		break;
	case Xing::SI:
		cout<<"������"<<endl;
		break;
	case Xing::ZHEFU:
		cout<<"�����ݷ�"<<endl;
		break;
	}
	
	delete pXings;
	pXings = NULL;
}
