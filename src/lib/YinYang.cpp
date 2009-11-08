#include "YinYang.h"

YinYang::YinYang(void)
{
}

YinYang::~YinYang(void)
{
}

bool YinYang::isYang()
{
	return this->yang;
}

bool YinYang::isYin()
{
	return !(this->yang);
}
