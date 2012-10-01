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
	QiMenDunJia(int jieqi, int yuan,boost::shared_ptr<Gan_Zhi> pShiGZ, boost::shared_ptr<Gan_Zhi> pRiGZ);
	~QiMenDunJia(void);
	static void printDiPan();
	void printDunJu();

private:
	//天盘
	TianPan tianPan[9];
	//人盘
	int renPan[8];
	//神盘
	int shenPan[8];

	//节气
	int jieqi;
	//时干
	int shiGan;
	//时支
	int shiZhi;
	//日干
	int riGan;
	//白昼还是黑夜
	bool isDay; 

	void setDunJu();
	void paiJu(int yuan, int xunshou);
	//断卦
	void duan();

	bool isYangDun;
	int dunju[3];
	TianPan _tianPan[9];
	int _shenPan[8];
	
	int zhiFu;
	int zhiShi;
	int ganPos;
	int zhiGong;

	int findPosByTianPanXing(int jiuxing);
	int findPosByDiPanXing(int jiuxing);
};

