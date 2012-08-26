#include "Month.h"

#include "Gua.h"

const int qiMenDiPan[9] = {BG_Kan, BG_Qian, BG_Dui, BG_Kun, BG_Li, BG_Xun, BG_Zhen, BG_Gen, BG_Zhong};

#pragma once
class QiMenDunJia
{
public:
	QiMenDunJia(int jieqi);
	~QiMenDunJia(void);
	static void printDiPan();

private:
	int jieqi;
	void setDunJu();
	bool isYangDun;
	int dunju[3];
};

