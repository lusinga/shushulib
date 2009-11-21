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
		pdz = new DiZhi_Chou();
		break;
	case DiZhi::DZyin:
		pdz = new DiZhi_Yin();
		break;
	case DiZhi::DZmao:
		pdz = new DiZhi_Mao();
		break;
	case DiZhi::DZchen:
		pdz = new DiZhi_Chen();
		break;
	case DiZhi::DZsi:
		pdz = new DiZhi_Si();
		break;
	case DiZhi::DZwu:
		pdz = new DiZhi_Wu();
		break;
	case DiZhi::DZwei:
		pdz = new DiZhi_Wei();
		break;
	case DiZhi::DZshen:
		pdz = new DiZhi_Shen();
		break;
	case DiZhi::DZyou:
		pdz = new DiZhi_You();
		break;
	case DiZhi::DZxu:
		pdz = new DiZhi_Xu();
		break;
	case DiZhi::DZhai:
		pdz = new DiZhi_Hai();
		break;
	}

	return pdz;
}
