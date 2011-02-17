#include "Tiangan.h"
#include "DiZhi.h"
#include "Xing.h"
#include "YinYang.h"

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

	GuiShen(TianGan* pTG, bool isDay);
	~GuiShen(void);

	string getName();

	DiZhi* pGod;
	int gsID;
	string* pName;
	Xing* pXing;
	YinYang* pYingYang;
};
