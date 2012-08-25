#pragma once
#include "ganzhi.h"

#include "Tiangan.h"
#include "DiZhi.h"

#include <boost/shared_ptr.hpp>

class Gan_Zhi :
	public GanZhi
{
public:
	Gan_Zhi(int iTG, int iDZ);
	virtual ~Gan_Zhi(void);

	virtual int getXing();
	
	virtual string getName();

	boost::shared_ptr<TianGan> pTG;
	boost::shared_ptr<DiZhi> pDZ;

	bool isXunKong(boost::shared_ptr<DiZhi> pDZToBeCheck);
	bool isSiDaKongWang(int xing);

	int getOrder();
	int getXunShou();

private:
	int order;
};
