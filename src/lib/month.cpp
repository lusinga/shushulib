#include "Month.h"


DiZhi* Month::buildZhi(int dzid)
{
	if(dzid == DiZhi::DZyin){
		return new DiZhi_Yin();
	}
	else if(dzid == DiZhi::DZmao)
	{
		return new DiZhi_Mao();
	}
	else
		return NULL;
}
