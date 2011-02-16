#include "JinKouJue.h"
#include "Month.h"

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

}

JinKouJue::~JinKouJue(void)
{
}

void JinKouJue::show()
{
	cout<<this->pYear->getName()<<"年"<<this->pMonth->getName()<<"月"<<this->pDay->getName()<<"日"<<this->pHour->getName()<<"时"<<endl;
	cout<<"地分："<<this->pDiFen->getName()<<endl;
	cout<<"月将："<<this->pYueJiang->getName()<<endl;
}
