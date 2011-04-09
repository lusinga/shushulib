#include "Tiangan.h"
#include "DiZhi.h"
#include "Xing.h"
#include "YinYang.h"

#include <boost/shared_ptr.hpp>

class GuiShen
{
public:
	static const int gsTianYi = 0;
	static const int gsTengShe = 1;
	static const int gsZhuQiu = 2;
	static const int gsLiuHe = 3;
	static const int gsGouChen =4;
	static const int gsQingLong = 5;
	static const int gsTianKong = 6;
	static const int gsBaiHu = 7;
	static const int gsTaiChang = 8;
	static const int gsXuanWu = 9;
	static const int gsTaiYin = 10;
	static const int gsTianHou = 11;

	GuiShen(shared_ptr<TianGan> pTG, bool isDay, shared_ptr<DiZhi> pDiFen);
	~GuiShen(void);

	string getName();

	shared_ptr<DiZhi> pDZ;
	int gsID;
	shared_ptr<string> pName;
	shared_ptr<Xing> pXing;
	shared_ptr<YinYang> pYinYang;
};
