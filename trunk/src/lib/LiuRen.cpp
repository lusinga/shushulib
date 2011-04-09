#include "liuren.h"

#include <iostream>
#include <boost/foreach.hpp>
#include <vector>
#include <map>
#include <algorithm>
#include <boost/shared_ptr.hpp>

using namespace std;

LiuRen::LiuRen(int month, int time, int gan, int zhi)
{
	this->month = month;
	this->time = time;
	this->riGan = gan;
	this->riZhi = zhi;
}

LiuRen::~LiuRen()
{

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
	cout<<endl<<"���̣�"<<endl<<endl;
	DiZhi* pdz = new DiZhi_Zi();
	formatPan(pdz);
	delete pdz;
	pdz = NULL;
}

void LiuRen::tianPan()
{
	cout<<endl<<"���̣�"<<endl<<endl;
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

	cout<<endl<<"�Ŀ�:"<<endl<<endl;
	cout<<pdz0->getName()<<" "<<pdz1->getName()<<" "
		<<pdz2->getName()<<" "<<pdz3->getName()<<" "<<endl;

	cout<<ptg1->getName()<<" "<<pdz0->getName()<<" "
		<<pdzr->getName()<<" "<<pdz2->getName()<<" "<<endl;

}

void LiuRen::printSanChuan(bool isGan)
{
	TianGan* ptg;
	DiZhi* pdz1;
	DiZhi* pdz2;
	DiZhi* pdz3;

	cout<<endl<<"������"<<endl;

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
	vector<int> zeiKe;
	vector<int> zeiKeBiYong;
	vector<int> keKe;
	vector<int> keKeBiYong;

	izei=0;
	izei_he=0;
	ike=0;
	ike_he=0;

	pgzl[0] = Month::buildGan(this->kelow[0]);
	for(int i=1;i<4;i++)
		pgzl[i] = Month::buildZhi(this->kelow[i]);

	for(int i=0;i<4;i++)
		pgzh[i] = Month::buildZhi(this->kehigh[i]);

	//�����¿���Ϊ��
	for(int i=0;i<4;i++)
	{
		if(pgzl[i]->ke(pgzh[i]))
		{
			zeiKe.push_back(i);
			if(YinYang::isHe(this->riGan, kehigh[i]))
			{
				zeiKeBiYong.push_back(i);
			}
		}
	}

	izei=(int)zeiKe.size();
	izei_he=zeiKeBiYong.size();

	cout<<"[Debug]����"<<izei<<"�����Ρ�"<<endl;
	cout<<"[Debug]����"<<izei_he<<"�����α��á�"<<endl;

	if (izei == 1){ 
		//cout<<"����һ������!"<<endl;
		this->sanchuan[0] = this->kehigh[zeiKe.front()];
		this->sanchuan[1] =this->tianpan[this->sanchuan[0]];
		this->sanchuan[2] =this->tianpan[this->sanchuan[1]];
		this->printSanChuan(false);
		return;
	}

	if (izei_he == 1){ 
		cout<<"�˿ο����ñ��÷����"<<endl;
		this->sanchuan[0] = this->kehigh[zeiKeBiYong.front()];
		this->sanchuan[1] =this->tianpan[this->sanchuan[0]];
		this->sanchuan[2] =this->tianpan[this->sanchuan[1]];
		this->printSanChuan(false);
		return;
	}
	//����ʹ���溦����������ҳ�ͬʱ���Ŀ�
	else if(izei > 1)
	{
		map<int, int> shehai;
		BOOST_FOREACH(int ii, zeiKe)
		{
			shehai.insert(map<int,int>::value_type(ii,walk(kelow[ii],kehigh[ii])));
		}

		cout<<"�˿ο������溦�����"<<endl;
		int iPos = max_element(shehai.begin(),shehai.end())->first;
		this->sanchuan[0] = this->kehigh[iPos];
		this->sanchuan[1] =this->tianpan[this->sanchuan[0]];
		this->sanchuan[2] =this->tianpan[this->sanchuan[1]];
		this->printSanChuan(false);


	}

	//�ˣ��Ͽ���Ϊ��
	for(int i=0;i<4;i++)
	{
		if(pgzh[i]->ke(pgzl[i]))
		{
			keKe.push_back(i);
			if(YinYang::isHe(this->riGan, kehigh[i]))
			{
				keKeBiYong.push_back(i);
			}
		}
	}

	izei=keKe.size();
	izei_he=keKeBiYong.size();

	cout<<"[Debug]����"<<ike<<"���˿Ρ�"<<endl;
	cout<<"[Debug]����"<<ike_he<<"���˿α��á�"<<endl;

	if (izei == 1){ 
		cout<<"����һ���˿�!"<<endl;
		this->sanchuan[0] = this->kehigh[keKe.front()];
		this->sanchuan[1] =this->tianpan[this->sanchuan[0]];
		this->sanchuan[2] =this->tianpan[this->sanchuan[1]];
		this->printSanChuan(false);
		return;
	}

	if (izei_he == 1){ 
		cout<<"�˿ο����ñ��÷����"<<endl;
		this->sanchuan[0] = this->kehigh[keKeBiYong.front()];
		this->sanchuan[1] =this->tianpan[this->sanchuan[0]];
		this->sanchuan[2] =this->tianpan[this->sanchuan[1]];
		this->printSanChuan(false);
		return;
	}
	//����ʹ���溦����������ҳ�ͬʱ���Ŀ�
	else if(ike > 1)
	{
		map<int, int> shehai;
		BOOST_FOREACH(int ii, keKe)
		{
			shehai.insert(map<int,int>::value_type(ii,walk(kelow[ii],kehigh[ii])));
		}

		cout<<"�˿ο������溦�����"<<endl;
		int iPos = max_element(shehai.begin(),shehai.end())->first;
		this->sanchuan[0] = this->kehigh[iPos];
		this->sanchuan[1] =this->tianpan[this->sanchuan[0]];
		this->sanchuan[2] =this->tianpan[this->sanchuan[1]];
		this->printSanChuan(false);
	}

	//walk(DiZhi::DZmao,DiZhi::DZchou);
	//walk(DiZhi::DZchou, DiZhi::DZhai);
}

int LiuRen::walk(int start, int end)
{
	cout<<endl;
	int kecount = 0;

	if(end<start) end+=12;

	DiZhi* pMe = Month::buildZhi(end);

	for(int i=start; i<=end; i++)
	{
		DiZhi* pHe = Month::buildZhi(i);
		//cout<<pHe->getName();
		if(pHe->ke(pMe))
			kecount++;
	}
	cout<<"�����ڻع���̱�λ�Ĺ����У����Ʊ���"<<kecount<<"��"<<endl<<endl;

	return kecount;
}

void LiuRen::duanKe()
{
	cout<<endl;

	//ʼ��Σ�ֻ��һ�������ϡ�
	if (izei == 1 && ike == 0)
	{
		cout<<"����һ��ʼ��Σ�"<<endl;
	}

	if(izei ==0 && ike == 1)
	{
		cout<<"����һ��Ԫ�׿�!"<<endl;
	}

	if(izei ==1 && ike >0 )
	{
		cout<<"����һ�������"<<endl;
	}

	if(izei_he==1)
	{
		cout<<"����һ�����ÿ�"<<endl;
	}

	if(ike_he==1)
	{
		cout<<"����һ��֪һ��"<<endl;
	}

	cout<<"========================================================"<<endl;

}
