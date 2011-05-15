#include "DiZhi.h"
#include <iostream>

using namespace std;

DiZhi::DiZhi(void)
{
	
}

DiZhi::~DiZhi(void)
{
}


bool DiZhi::he(int he1, int he2)
{
	return ((he1 + he2) % 12 == 1);
}

bool DiZhi::sanhe(int he1, int he2, int he3)
{
	return ((he1 +4) % 12 == he2) && ((he2 +4) % 12 == he3);
}


bool DiZhi::chong(int chong1, int chong2)
{
	return (chong1 + 6) % 12 == chong2;
}

int DiZhi::getDzid()
{
	return this->dzid;
}

bool DiZhi::he(boost::shared_ptr<DiZhi> pz)
{
	bool ishe = he(this->getDzid(),pz->getDzid());
	if(ishe)
	{
		cout<<this->getName()<<"Óë"<<pz->getName()<<"ºÏ"<<endl;
	}
	return ishe;
}

bool DiZhi::chong(boost::shared_ptr<DiZhi> pz)
{
	bool ischong = chong(this->getDzid(),pz->getDzid());
	if(ischong)
	{
		cout<<this->getName()<<pz->getName()<<"Ïà³å"<<endl;
	}
	/*else
	{
		cout<<".";
	}*/
	return ischong;
}

bool DiZhi::sanhe(boost::shared_ptr<DiZhi> pz2, boost::shared_ptr<DiZhi> pz3)
{
	return sanhe(this->getDzid(), pz2->getDzid(), pz3->getDzid());
}

int DiZhi::getMonth(void)
{
	return (this->dzid -1 ) %12;
}
