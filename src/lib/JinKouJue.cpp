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

	cout<<"[debug]isDay="<<isDay<<endl;

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

	cout<<"=================================================="<<endl;
}

string JinKouJue::parseYueJiangName()
{
	string name[] = {"登明","河魁","从魁","传送","小吉","胜光","太乙","天罡","太冲","功曹","大吉","神后"};
	return name[11-this->pYueJiang->getDzid()];
}
