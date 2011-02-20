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
	cout<<this->pYear->getName()<<"年"<<this->pMonth->getName()<<"月"<<this->pDay->getName()<<"日"<<this->pHour->getName()<<"时"<<endl;
	cout<<"人元："<<this->pRenYuan->getName()<<endl;
	cout<<"贵神："<<Month::wuZiYuanDu(pDay->pTG,this->pGuiShen->pGod)->getName()<<this->pGuiShen->getName()<<endl;
	cout<<"月将："<<Month::wuZiYuanDu(pDay->pTG,this->pYueJiang)->getName()<<this->pYueJiang->getName()<<"("<<parseYueJiangName()<<")"<<endl;
	cout<<"地分："<<this->pDiFen->getName()<<endl;

	duanKe();

	cout<<"=================================================="<<endl;
}

string JinKouJue::parseYueJiangName()
{
	string name[] = {"登明","河魁","从魁","传送","小吉","胜光","太乙","天罡","太冲","功曹","大吉","神后"};
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
		cout<<"纯阴反阳，以将为用，主事体由隐秘开始向公开发展。问事体由女子转向男子或由男子转向女子，事体开始向有利的因素发展，做事不可操之过急。"<<endl;
		bYongShenIsJiang = true;
		break;
	case 1:
		cout<<"以阳为用，主事在男。事物在向正面方向发展，前途光明。"<<endl;
		if (this->pYueJiang->getDzid() % 2 == 0)
		{
			//将是阳，则以阳为用即以将为用。
			bYongShenIsJiang = true;
		}
		else
		{
			bYongShenIsJiang = false;
		}
		break;
	case 2:
		cout<<"二阴二阳，以将为用，事物还不太明朗化，问事件男女不明，吉凶不定。看四位配合决断。"<<endl;
		bYongShenIsJiang = false;
		break;
	case 3:
		cout<<"以阴为用，主事在女。事物正向反方向发展，前途不明。"<<endl;
		if (this->pYueJiang->getDzid() % 2 != 0)
		{
			//将是阴，则以阴为用即以将为用。
			bYongShenIsJiang = true;
		}
		else
		{
			bYongShenIsJiang = false;
		}
		break;
	case 4:
		cout<<"纯阳反阴，以神为用。四位纯阳，阳气过旺。旺极转衰，事体开始走向它的反面，不利因素开始增加，事体开始过渡，由男转为女，或由女转为男。如处在山的顶峰，向下发展势在必然。故做事易速不易迟。"<<endl;
		bYongShenIsJiang = false;
		break;
	default:
		cout<<"阴阳错乱了。"<<endl;
		break;
	}

	Xing** pXings = new Xing*[4];
	//人，贵，月，地
	pXings[0] = pRenYuan->buildXing();
	pXings[1] = pGuiShen->pXing;
	pXings[2] = pYueJiang->buildXing();
	pXings[3] = pDiFen->buildXing();

	Xing* pYongShenXing = bYongShenIsJiang? pXings[2] : pXings[1];

	int state = Xing::getState(pYongShenXing,pXings,4);
	switch(state)
	{
	case Xing::WANG:
		cout<<"用神旺"<<endl;
		break;
	case Xing::XIANG:
		cout<<"用神相"<<endl;
		break;
	case Xing::XIU:
		cout<<"用神休"<<endl;
		break;
	case Xing::QIU:
		cout<<"用神囚"<<endl;
		break;
	case Xing::SI:
		cout<<"用神死"<<endl;
		break;
	case Xing::ZHEFU:
		cout<<"用神蛰伏"<<endl;
		break;
	}
	
	delete pXings;
	pXings = NULL;
}
