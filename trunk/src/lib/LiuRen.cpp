#include "liuren.h"

#include <iostream>

using namespace std;

LiuRen::LiuRen(int month, int time, int gan, int zhi)
{
	this->month = month;
	this->time = time;
	this->riGan = gan;
	this->riZhi = zhi;
}

void LiuRen::formatPan(DiZhi* pdz)
{
	DiZhi* dzs[12];
	dzs[0] = pdz;
	for(int i=1;i<12;i++)
	{
		dzs[i]= Month::buildZhi(pdz->getDzid() + i);
	}

	cout<<dzs[5]->getName()<<dzs[6]->getName()<<dzs[7]->getName()<<dzs[8]->getName()<<endl;
	cout<<dzs[4]->getName()<<"    "<<dzs[9]->getName()<<endl;
	cout<<dzs[3]->getName()<<"    "<<dzs[10]->getName()<<endl;
	cout<<dzs[2]->getName()<<dzs[1]->getName()<<dzs[0]->getName()<<dzs[11]->getName()<<endl;

	for(int i=1;i<12;i++)
	{
		delete dzs[i];
		dzs[i] = NULL;
	}

}

void LiuRen::diPan()
{
	cout<<endl<<"µØÅÌ£º"<<endl<<endl;
	DiZhi* pdz = new DiZhi_Zi();
	formatPan(pdz);
	delete pdz;
	pdz = NULL;
}

void LiuRen::tianPan()
{
	cout<<endl<<"ÌìÅÌ£º"<<endl<<endl;
	int tian_start = Month::getYueJiang(this->month)-this->time;
	formatPan(Month::buildZhi(tian_start));
	
	for(int i=0;i<12;i++)
	{
		this->tianpan[i] = (tian_start+i>=0? (tian_start+i) %12 : (tian_start+i) %12 + 12);
	}
}

void LiuRen::siKe()
{
	TianGan* ptg1 = Month::buildGan(this->riGan);
	this->kelow[0] = this->riGan;
	this->kelow[1] = this->kehigh[0] = this->tianpan[ptg1->getJiGong()];
	this->kehigh[1] = this->tianpan[kelow[1]];
	
	this->kelow[2] = this->riZhi;
	this->kelow[3] = this->kehigh[2] = this->tianpan[kelow[2]]; 
	this->kehigh[3] = this->tianpan[kelow[3]];

	DiZhi* pdz0 = Month::buildZhi(kehigh[0]);
	DiZhi* pdz1 = Month::buildZhi(kehigh[1]);
	DiZhi* pdz2 = Month::buildZhi(kehigh[2]);
	DiZhi* pdz3 = Month::buildZhi(kehigh[3]);

	DiZhi* pdzr = Month::buildZhi(kelow[2]);

	cout<<endl<<"ËÄ¿Î:"<<endl<<endl;
	cout<<pdz0->getName()<<" "<<pdz1->getName()<<" "
		<<pdz2->getName()<<" "<<pdz3->getName()<<" "<<endl;

	cout<<ptg1->getName()<<" "<<pdz0->getName()<<" "
		<<pdzr->getName()<<" "<<pdz2->getName()<<" "<<endl;
}
