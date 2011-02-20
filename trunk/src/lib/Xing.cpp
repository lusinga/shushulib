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
		cout<<this->getFeature()<<"��"<<xing->getFeature()<<endl;
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
		cout<<this->getFeature()<<"��"<<xing->getFeature()<<endl;
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

	//�����н�ľˮ�����ظ������
	if(iJin<2 && iMu < 2 && iShui <2 && iHuo<2 && iTu<2)
	{
		//�쿴��λ���ܿˣ����ܿ�����
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
	
	return index;
}
