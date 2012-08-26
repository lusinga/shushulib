#include "Gua.h"

#include <boost/make_shared.hpp>

using boost::make_shared;

boost::shared_ptr<string> BaGua::getGuaName(int gua)
{
	return boost::make_shared<string>(GuaName[(gua-1)%9]);
}

int BaGua::getPos(int gua)
{
	switch (gua % 9)
	{
	case BG_Kan:
		return 0;
		break;
	case BG_Qian:
		return 1;
		break;
	case BG_Dui:
		return 2;
		break;
	case BG_Kun:
		return 3;
		break;
	case BG_Li:
	case 0:
		return 4;
		break;
	case BG_Xun:
		return 5;
		break;
	case BG_Zhen:
		return 6;
		break;
	case BG_Gen:
		return 7;
		break;
	case BG_Zhong:
		return 8;
		break;
	default:
		return -1;//Impossible 
	}
}
