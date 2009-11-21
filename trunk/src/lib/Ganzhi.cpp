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
		cout<<this->getName()<<"¿Ë"<<pdz->getName()<<endl;
		return true;
	}
	else return false;
}
