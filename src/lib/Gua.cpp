#include "Gua.h"

#include <boost/make_shared.hpp>

using boost::make_shared;

boost::shared_ptr<string> BaGua::getGuaName(int gua)
{
	return boost::make_shared<string>(GuaName[(gua-1)%9]);
}
