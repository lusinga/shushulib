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

int Xing::whichWang(Xing** pXing, int numbers)
{
	int index = -1;

	int iJin =0;
	int iMu = 0;
	int iShui = 0;
	int iHuo = 0;
	int iTu = 0;

	for(int i=0;i<numbers;i++)
	{
		switch(pXing[i]->feature)
		{
		case HUO:
			iHuo++;
			break;
		case JIN:
			iJin++;
			break;
		case MU:
			iMu++;
			break;
		case SHUI:
			iShui++;
			break;
		case TU:
			iTu++;
			break;
		default:
			break;
		}
	}

	//五行中金木水土火不重复的情况
	if(iJin<2 && iMu < 2 && iShui <2 && iHuo<2 && iTu<2)
	{
		//察看哪位不受克，不受克者旺
		for(int i=0;i<numbers;i++)
		{
			bool iBeenKe = false;
			for(int j=0;j<numbers;j++)
			{
				if (i==j)
					continue;
				if(pXing[j]->ke(pXing[i]))
				{
					iBeenKe = true;
					break;
				}
			}
			if (!iBeenKe)
			{
				index = i;
				break;
			}
		}
	}
	else if(iJin == 2 || iMu == 2 || iShui == 2 || iHuo == 2 || iTu == 2)
	{
		if (iJin == 1 || iMu == 1 || iShui == 1 || iHuo == 1 || iTu == 1)
		{
			//克他爻者为旺
			for(int i=0;i<numbers;i++)
			{
				for(int j=0;j<numbers;j++)
				{
					if(i==j) 
						continue;
					if(pXing[i]->ke(pXing[j]))
					{
						index = i;
						break;
					}
				}
			}
		}
		else
		{
			//受生者为旺
			for(int i=0;i<numbers;i++)
			{
				for(int j=0;j<numbers;j++)
				{
					if(i==j) 
						continue;
					if(pXing[j]->sheng(pXing[i]))
					{
						index = i;
						break;
					}
				}
			}
		}

	}
	else if(iJin == 3 || iMu == 3 || iShui == 3 || iHuo == 3 || iTu == 3)
	{

	}
	else if(iJin == 4 || iMu == 4 || iShui == 4 || iHuo == 4 || iTu == 4)
	{

	}
	else
	{

	}

	return index;
}

Xing* Xing::whichXingIsWang(Xing** pXing,int numbers)
{
	return pXing[whichWang(pXing,numbers)];
}

int Xing::getState(Xing* pXing, Xing** pXings, int numbers)
{
	Xing* pWang = whichXingIsWang(pXings,numbers);
	
	if(pWang->getFeature() == pXing->getFeature())
	{
		return WANG;
	}
	else if(pWang->sheng(pXing))
	{
		return XIANG;//旺生者为相
	}
	else if(pWang->ke(pXing))
	{
		return SI;//旺克者为死
	}
	else if(pXing->sheng(pWang))
	{
		return XIU;//生旺者为休
	}
	else if(pXing->ke(pWang))
	{
		return QIU;//克旺者囚
	}
}
