#include "Month.h"


DiZhi* Month::buildZhi(int dzid)
{
	DiZhi* pdz = NULL;
	switch(dzid)
	{
	case DiZhi::DZzi:
		pdz = new DiZhi_Zi();
		break;
	case DiZhi::DZchou:
		break;
	case DiZhi::DZyin:
		break;
	case DiZhi::DZmao:
		break;
	}

	return pdz;
}
