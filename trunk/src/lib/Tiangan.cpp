#include "tiangan.h"
#include "dizhi.h"

int TianGan::getJiGong()
{
	return this->JiGong[this->tgid];	
};

/**
 * �׿������ҿγ�
 * �������Ȳ�����
 * ������δ����λ
 * �����ɺ�������
 * �������������
 * ��������������
 */
int TianGan::JiGong[] = {
	DiZhi::DZyin, 
	DiZhi::DZchen,
	DiZhi::DZsi,
	DiZhi::DZwei,
	DiZhi::DZsi,
	DiZhi::DZwei,
	DiZhi::DZshen,
	DiZhi::DZxu,
	DiZhi::DZhai,
	DiZhi::DZchou,
};

int TianGan::getTgid()
{
	return this->tgid;
}
