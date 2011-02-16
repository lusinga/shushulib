#pragma once
#include "Gan_Zhi.h"

class JinKouJue
{
public:
	JinKouJue(Gan_Zhi* pYear,Gan_Zhi* pMonth,Gan_Zhi* pDay,Gan_Zhi* pHour,DiZhi* pDiFen);
	~JinKouJue(void);

	Gan_Zhi* pYear;
	Gan_Zhi* pMonth;
	Gan_Zhi* pDay;
	Gan_Zhi* pHour;

	DiZhi* pDiFen;

	DiZhi* pYueJiang; 

	void show();

};

