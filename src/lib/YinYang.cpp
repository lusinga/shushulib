#include "YinYang.h"

YinYang::YinYang(void)
{
}

YinYang::~YinYang(void)
{
}

bool YinYang::isYang()
{
	return this->yinyang;
}

bool YinYang::isYin()
{
	return !(this->yinyang);
}
