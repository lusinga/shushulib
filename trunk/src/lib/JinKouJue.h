#pragma once
#include "Gan_Zhi.h"
#include "GuiShen.h"
#include <vector>
#include <boost/shared_ptr.hpp>

class JinKouJue
{
public:
	JinKouJue(boost::shared_ptr<Gan_Zhi> pYear,boost::shared_ptr<Gan_Zhi> pMonth,
		boost::shared_ptr<Gan_Zhi> pDay,boost::shared_ptr<Gan_Zhi> pHour,
		boost::shared_ptr<DiZhi> pDiFen);
	~JinKouJue(void);

	boost::shared_ptr<Gan_Zhi> pYear;
	boost::shared_ptr<Gan_Zhi> pMonth;
	boost::shared_ptr<Gan_Zhi> pDay;
	boost::shared_ptr<Gan_Zhi> pHour;

	boost::shared_ptr<DiZhi> pDiFen;

	boost::shared_ptr<DiZhi> pYueJiang;
	boost::shared_ptr<GuiShen> pGuiShen;
	boost::shared_ptr<TianGan> pRenYuan;

	boost::shared_ptr<TianGan> pJiangGan;
	boost::shared_ptr<TianGan> pShenGan;

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
	vector<boost::shared_ptr<TianGan> > gans;
	vector<boost::shared_ptr<DiZhi> > zhis;
	vector<boost::shared_ptr<Gan_Zhi> > sizhu;
};
