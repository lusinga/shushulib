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
		cout<<this->getFeature()<<"¿Ë"<<xing->getFeature()<<endl;
		return true;
	}
	else return false;
}

bool Xing::sheng(int shenger, int shengee)
{
	if (shenger == MU && shengee == HUO) return true;
	else if (shenger == HUO && shengee == TU) return true;
	else if (shenger == TU && shengee == JIN) return true;
	else if (shenger == JIN && shengee == SHUI) return true;
	else if (shenger == SHUI && shengee == MU) return true;
	else return false;
}

bool Xing::ke(int ker, int kee)
{
	if (ker == JIN && kee == MU) return true;
	else if(ker == MU && kee == TU) return true;
	else if(ker == TU && kee == SHUI) return true;
	else if(ker == SHUI && kee == HUO) return true;
	else if(ker == HUO && kee == JIN) return true;
	else return false;
}

bool Xing::sheng(Xing* xing)
{
	if (sheng(this->feature,xing->feature)){
		cout<<this->getFeature()<<"Éú"<<xing->getFeature()<<endl;
		return true;
	}
	else return false;
}
