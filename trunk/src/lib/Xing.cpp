#include "Xing.h"
#include <iostream>
#include "Jin.h"
#include "Mu.h"
#include "Shui.h"
#include "Tu.h"
#include "Huo.h"

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
	else if(iJin == 2 || iMu == 2 || iShui == 2 || iHuo == 2 || iTu == 2)
	{
		//if (iJin == 1 || iMu == 1 || iShui == 1 || iHuo == 1 || iTu == 1)
		{
			//����س��Ϊ��
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
		if(index == -1)
		//else
		{
			//������Ϊ��
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
		//����Ϊ��
		if(pXing[0]->getFeature()==pXing[1]->getFeature())
		{
			index = 0;
		}
		else if(pXing[0]->getFeature()==pXing[2]->getFeature())
		{
			index = 0;
		}
		else
		{
			index = 1;
		}
	}
	else if(iJin == 4 || iMu == 4 || iShui == 4 || iHuo == 4 || iTu == 4)
	{
		index = numbers;
	}
	else
	{
		index = -1;
	}

	return index;
}

Xing* Xing::whichXingIsWang(Xing** pXing,int numbers)
{
	int index = whichWang(pXing,numbers);
	if(index == numbers)
		return NULL;
	else
		return pXing[index];
}

int Xing::getState(Xing* pXing, Xing** pXings, int numbers)
{
	Xing* pWang = whichXingIsWang(pXings,numbers);

	if(pWang == NULL)
		return ZHEFU;
	
	if(pWang->getFeature() == pXing->getFeature())
	{
		return WANG;
	}
	else if(pWang->sheng(pXing))
	{
		return XIANG;//������Ϊ��
	}
	else if(pWang->ke(pXing))
	{
		return SI;//������Ϊ��
	}
	else if(pXing->sheng(pWang))
	{
		return XIU;//������Ϊ��
	}
	else if(pXing->ke(pWang))
	{
		return QIU;//��������
	}
	else
		return ZHEFU;
}

Xing* Xing::buildXing(int xing)
{
	int xing2 = (xing+5) % 5;

	switch (xing2)
	{
	case Xing::HUO:
		return new Huo();
		break;
	case Xing::JIN:
		return new Jin();
		break;
	case Xing::MU:
		return new Mu();
		break;
	case Xing::SHUI:
		return new Shui();
		break;
	case Xing::TU:
		return new Tu();
		break;
	default:
		return NULL;
		break;
	}
}
