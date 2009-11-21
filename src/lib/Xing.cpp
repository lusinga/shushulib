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
		//cout<<this->getFeature()<<"¿Ë"<<xing->getFeature()<<endl;
		cout<<this->feature<<"¿Ë"<<xing->feature<<endl;
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
		cout<<this->getFeature()<<"Éú"<<xing->getFeature()<<endl;
		return true;
	}
	else return false;
}
