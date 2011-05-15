#include "Xing.h"
#include <iostream>
#include "Jin.h"
#include "Mu.h"
#include "Shui.h"
#include "Tu.h"
#include "Huo.h"

#include <boost/make_shared.hpp>

using boost::make_shared;

Xing::Xing(void)
: feature(0)
{
}

Xing::~Xing(void)
{
}

bool Xing::ke(boost::shared_ptr<Xing> xing)
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

bool Xing::sheng(boost::shared_ptr<Xing> xing)
{
	if (sheng(this->feature,xing->feature)){
		cout<<this->getFeature()<<"生"<<xing->getFeature()<<endl;
		return true;
	}
	else return false;
}

int Xing::whichWang(boost::shared_ptr<Xing>* pXings, int numbers)
{
	int index = -1;

	int iJin =0;
	int iMu = 0;
	int iShui = 0;
	int iHuo = 0;
	int iTu = 0;

	for(int i=0;i<numbers;i++)
	{
		switch(pXings[i]->feature)
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
				if(pXings[j]->ke(pXings[i]))
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
			//克他爻者为旺
			for(int i=0;i<numbers;i++)
			{
				for(int j=0;j<numbers;j++)
				{
					if(i==j) 
						continue;
					if(pXings[i]->ke(pXings[j]))
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
			//受生者为旺
			for(int i=0;i<numbers;i++)
			{
				for(int j=0;j<numbers;j++)
				{
					if(i==j) 
						continue;
					if(pXings[j]->sheng(pXings[i]))
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
		//多着为旺
		if(pXings[0]->getFeature()==pXings[1]->getFeature())
		{
			index = 0;
		}
		else if(pXings[0]->getFeature()==pXings[2]->getFeature())
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

boost::shared_ptr<Xing> Xing::whichXingIsWang(boost::shared_ptr<Xing>* pXing,int numbers)
{
	int index = whichWang(pXing,numbers);
	if(index == numbers)
		return boost::shared_ptr<Xing>();
	else
		return pXing[index];
}

int Xing::getState(boost::shared_ptr<Xing> pXing, boost::shared_ptr<Xing>* pXings, int numbers)
{
	boost::shared_ptr<Xing> pWang = whichXingIsWang(pXings,numbers);

	if(pWang == NULL)
		return ZHEFU;
	
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
	else
		return ZHEFU;
}

boost::shared_ptr<Xing> Xing::buildXing(int xing)
{
	int xing2 = (xing+5) % 5;

	switch (xing2)
	{
	case Xing::HUO:
		return boost::make_shared<Huo>();
		break;
	case Xing::JIN:
		return boost::make_shared<Jin>();
		break;
	case Xing::MU:
		return boost::make_shared<Mu>();
		break;
	case Xing::SHUI:
		return boost::make_shared<Shui>();
		break;
	case Xing::TU:
		return boost::make_shared<Tu>();
		break;
	default:
		return boost::shared_ptr<Xing>();
		break;
	}
}
