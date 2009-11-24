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
	cout<<endl<<"地盘："<<endl<<endl;
	DiZhi* pdz = new DiZhi_Zi();
	formatPan(pdz);
	delete pdz;
	pdz = NULL;
}

void LiuRen::tianPan()
{
	cout<<endl<<"天盘："<<endl<<endl;
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

	cout<<endl<<"四课:"<<endl<<endl;
	cout<<pdz0->getName()<<" "<<pdz1->getName()<<" "
		<<pdz2->getName()<<" "<<pdz3->getName()<<" "<<endl;

	cout<<ptg1->getName()<<" "<<pdz0->getName()<<" "
		<<pdzr->getName()<<" "<<pdz2->getName()<<" "<<endl;

/*	delete ptg1;
	ptg1 = NULL;
	delete pdz0;
	pdz0 = NULL;
	delete pdz1;
	pdz1 = NULL;
	delete pdz2;
	pdz2 = NULL;
	delete pdz3;
	pdz3 = NULL;
	delete pdzr;
	pdzr = NULL;*/
}

void LiuRen::printSanChuan(bool isGan)
{
	TianGan* ptg;
	DiZhi* pdz1;
	DiZhi* pdz2;
	DiZhi* pdz3;

	cout<<endl<<"三传："<<endl;

	if(isGan){
		ptg = Month::buildGan(this->sanchuan[0]);
		cout<<ptg->getName()<<endl;
	}
	else{
		pdz1 = Month::buildZhi(this->sanchuan[0]);
		cout<<pdz1->getName()<<endl;
	}

	pdz2 = Month::buildZhi(this->sanchuan[1]);
	cout<<pdz2->getName()<<endl;
	pdz3 = Month::buildZhi(this->sanchuan[2]);
	cout<<pdz3->getName()<<endl;
}

void LiuRen::sanChuan()
{
	GanZhi* pgzh[4];
	GanZhi* pgzl[4];

	pgzl[0] = Month::buildGan(this->kelow[0]);
	for(int i=1;i<4;i++)
		pgzl[i] = Month::buildZhi(this->kelow[i]);

	for(int i=0;i<4;i++)
		pgzh[i] = Month::buildZhi(this->kehigh[i]);

	//贼，下克上为贼
	int izei=0;
	int zeipos = -1;
	int izei_he=0;
	int zei_he_pos = -1;

	for(int i=0;i<4;i++)
	{
		if(pgzl[i]->ke(pgzh[i]))
		{
			izei++;
			zeipos = i;
			if(YinYang::isHe(this->riGan, kehigh[i]))
			{
				izei_he++;
				zei_he_pos = i;
			}
		}
	}
	
	if (izei == 1){ 
		cout<<"这是一个贼课!"<<endl;
		this->sanchuan[0] = this->kehigh[zeipos];
		this->sanchuan[1] =this->tianpan[this->sanchuan[0]];
		this->sanchuan[2] =this->tianpan[this->sanchuan[1]];
		this->printSanChuan(false);
		return;
	}

	if (izei_he == 1){ 
		cout<<"此课可以用比用法解决"<<endl;
		this->sanchuan[0] = this->kehigh[zei_he_pos];
		this->sanchuan[1] =this->tianpan[this->sanchuan[0]];
		this->sanchuan[2] =this->tianpan[this->sanchuan[1]];
		this->printSanChuan(false);
		return;
	}
	
	//上克下为克
	int ike=0;
	int kepos = -1;
	int ike_he=0;
	int ke_he_pos = -1;

	for(int i=0;i<4;i++)
	{
		if(pgzh[i]->ke(pgzl[i]))
		{
			ike++;
			kepos = i;
			if(YinYang::isHe(this->riGan, kehigh[i]))
			{
				ike_he++;
				ke_he_pos = i;
			}
		}
	}

	if (ike == 1){ 
		cout<<"这是一个克课!"<<endl;
		this->sanchuan[0] = this->kehigh[kepos];
		this->sanchuan[1] =this->tianpan[this->sanchuan[0]];
		this->sanchuan[2] =this->tianpan[this->sanchuan[1]];
		this->printSanChuan(false);
		return;
	}

	if (ike_he == 1){ 
		cout<<"此课可以用比用法解决"<<endl;
		this->sanchuan[0] = this->kehigh[ke_he_pos];
		this->sanchuan[1] =this->tianpan[this->sanchuan[0]];
		this->sanchuan[2] =this->tianpan[this->sanchuan[1]];
		this->printSanChuan(false);
		return;
	}

}
