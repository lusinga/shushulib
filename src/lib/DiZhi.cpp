#include "DiZhi.h"


DiZhi::DiZhi(void)
{
	
}


DiZhi::~DiZhi(void)
{
}


bool DiZhi::he(int he1, int he2)
{
	return (he1 + he2) % 12 == 1;
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

bool DiZhi::he(DiZhi* pz)
{
	return he(this->getDzid(),pz->getDzid());
}

bool DiZhi::chong(DiZhi* pz)
{
	return chong(this->getDzid(),pz->getDzid());
}

bool DiZhi::sanhe(DiZhi* pz2, DiZhi* pz3)
{
	return sanhe(this->getDzid(), pz2->getDzid(), pz3->getDzid());
}
