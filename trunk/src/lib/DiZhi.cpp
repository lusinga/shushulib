#include "DiZhi.h"
#include "Tiangan.h"
#include <iostream>
#include <vector>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>

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

boost::shared_ptr<std::vector<int>> DiZhi::getJiGongTianGanList()
{
	boost::shared_ptr<std::vector<int>> tgs = boost::make_shared<std::vector<int>>();
	switch(dzid)
	{
	case DZyin:
		tgs->push_back(TGjia);
		break;
	case DZchen:
		tgs->push_back(TGyi);
		break;
	case DZsi:
		tgs->push_back(TGbing);
		tgs->push_back(TGwu);
		break;
	case DZwei:
		tgs->push_back(TGding);
		tgs->push_back(TGji);
		break;
	case DZshen:
		tgs->push_back(TGgeng);
		break;
	case DZxu:
		tgs->push_back(TGxin);
		break;
	case DZhai:
		tgs->push_back(TGren);
		break;
	case DZchou:
		tgs->push_back(TGgui);
		break;
	default:
		break;
	}

	return tgs;
}
