#pragma once
#include "Gan_Zhi.h"
#include "GuiShen.h"
#include <vector>

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
	GuiShen* pGuiShen;
	TianGan* pRenYuan;

	TianGan* pJiangGan;
	TianGan* pShenGan;

	bool bYongShenIsJiang;

	void show();

	void shensha();

	void duanKe();

private:
	string parseYueJiangName();
	vector<TianGan*> gans;
	vector<DiZhi*> zhis;

};

