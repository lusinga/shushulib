#include "tiangan.h"
#include "dizhi.h"

int TianGan::getJiGong()
{
	return this->JiGong[this->tgid];
};

/**
 * 甲课寅上乙课辰
 * 丙戌在巳不须论
 * 丁己在未庚申位
 * 辛戌壬亥定其真
 * 癸课由来丑上坐
 * 分明不用四正辰
 */
int TianGan::JiGong[] = {
	DZyin,
	DZchen,
	DZsi,
	DZwei,
	DZsi,
	DZwei,
	DZshen,
	DZxu,
	DZhai,
	DZchou,
};

int TianGan::getTgid()
{
	return this->tgid;
}

int TianGan::getHe()
{
	return (tgid + 5) % 10;
}
