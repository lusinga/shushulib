#include "Month.h"

#include "Gua.h"
#include "Gan_Zhi.h"
#include "TianPan.h"

const int ShangYuan = 0;
const int ZhongYuan = 1;
const int XiaYuan   = 2;

const int qiMenDiPan[9] = {BG_Kan, BG_Qian, BG_Dui, BG_Kun, BG_Li, BG_Xun, BG_Zhen, BG_Gen, BG_Zhong};

#pragma once
class QiMenDunJia
{
public:
	QiMenDunJia(int jieqi, int yuan,boost::shared_ptr<Gan_Zhi> pGZ);
	~QiMenDunJia(void);
	static void printDiPan();
	void printDunJu();

private:
	int jieqi;
	int shiGan;
	int shiZhi;
	void setDunJu();
	void paiJu(int yuan, int xunshou);
	bool isYangDun;
	int dunju[3];
	int renPan[8];
	TianPan tianPan[9];
	//TianPan* pTianPan[9];
	TianPan tianPan2[9];
	int shenPan[8];
	int shenPan2[8];

	int zhiFu;
	int zhiShi;
	int ganPos;
};

