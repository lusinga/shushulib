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

	template<class T>
	inline void PRINT_ELEMENTS(const T& coll, const char* optcstr="")
	{
		typename T::const_iterator pos;

		cout<<optcstr;
		for(pos=coll.begin();pos!=coll.end();++pos)
		{
			cout<<*pos<<' ';
		}
		cout<<endl;
	}

private:
	string parseYueJiangName();
	vector<TianGan*> gans;
	vector<DiZhi*> zhis;
	vector<Gan_Zhi*> sizhu;
};

