#include "Xing.h"
#include <iostream>

Xing::Xing(void)
: feature(0)
{
}

Xing::~Xing(void)
{
}

bool Xing::ke(Xing* xing)
{
	if (ke(this->feature,xing->feature)){
		cout<<this->getFeature()<<"克"<<xing->getFeature()<<endl;
		return true;
	}
	else return false;
}

bool Xing::sheng(int shenger, int shengee)
{
	return ( (shenger + 1) % 5 == shengee);
}

bool Xing::ke(int ker, int kee)
{
	return ((ker + 2)%5 == kee);
}

bool Xing::sheng(Xing* xing)
{
	if (sheng(this->feature,xing->feature)){
		cout<<this->getFeature()<<"生"<<xing->getFeature()<<endl;
		return true;
	}
	else return false;
}

int Xing::whichWang(Xing* pXing, int numbers)
{
	int index = 0;

	int iJin =0;
	int iMu = 0;
	int iShui = 0;
	int iHuo = 0;
	int iTu = 0;

	for(int i=0;i<numbers;i++)
	{
		switch(pXing[i].feature)
		{
		case this->HUO:
			iHuo++;
			break;
		case this->JIN:
			iJin++;
			break;
		case this->MU:
			iMu++;
			break;
		case this->SHUI:
			iShui++;
			break;
		case this->TU:
			iTu++;
			break;
		default:
			break;
		}
	}

	//五行中金木水土火不重复的情况
	if(iJin<2 && iMu < 2 && iShui <2 && iHuo<2 && iTu<<2)
	{
		//察看哪位不受克，不受克者旺

	}
	
	return index;
}
