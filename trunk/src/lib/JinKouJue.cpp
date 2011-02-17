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
}

JinKouJue::~JinKouJue(void)
{
}

void JinKouJue::show()
{
	
	cout<<this->pYear->getName()<<"��"<<this->pMonth->getName()<<"��"<<this->pDay->getName()<<"��"<<this->pHour->getName()<<"ʱ"<<endl;
	cout<<"����"<<this->pGuiShen->getName()<<endl;
	cout<<"�½���"<<this->pYueJiang->getName()<<endl;
	cout<<"�ط֣�"<<this->pDiFen->getName()<<endl;
}
