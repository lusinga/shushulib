#include "ganzhi.h"
#include <iostream>

using namespace std;

GanZhi::GanZhi(void)
{
	
}


GanZhi::~GanZhi(void)
{
}

bool GanZhi::ke(GanZhi* pdz)
{
	if (Xing::ke(this->getXing(),pdz->getXing())){
		cout<<this->getName()<<Xing::transFeature(this->getXing());
		cout<<"¿Ë"<<pdz->getName()<<Xing::transFeature(pdz->getXing());
		cout<<endl;
		return true;
	}
	else return false;
}
