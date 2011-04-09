#pragma once
#include "Gan_Zhi.h"
#include "GuiShen.h"
#include <vector>
#include <boost/shared_ptr.hpp>

class JinKouJue
{
public:
	JinKouJue(shared_ptr<Gan_Zhi> pYear,shared_ptr<Gan_Zhi> pMonth,shared_ptr<Gan_Zhi> pDay,shared_ptr<Gan_Zhi> pHour,shared_ptr<DiZhi> pDiFen);
	~JinKouJue(void);

	shared_ptr<Gan_Zhi> pYear;
	shared_ptr<Gan_Zhi> pMonth;
	shared_ptr<Gan_Zhi> pDay;
	shared_ptr<Gan_Zhi> pHour;

	shared_ptr<DiZhi> pDiFen;

	shared_ptr<DiZhi> pYueJiang;
	shared_ptr<GuiShen> pGuiShen;
	shared_ptr<TianGan> pRenYuan;

	shared_ptr<TianGan> pJiangGan;
	shared_ptr<TianGan> pShenGan;

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
	vector<shared_ptr<TianGan>> gans;
	vector<shared_ptr<DiZhi>> zhis;
	vector<shared_ptr<Gan_Zhi>> sizhu;
};
