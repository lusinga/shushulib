#pragma once

#include "month.h"

class LiuRen
{
public:
	LiuRen(int month, int time, int riGan, int riZhi);
	~LiuRen();
	static void formatPan(DiZhi* pdz);
	void diPan();
	void tianPan();
	void siKe(); 
	void sanChuan();
	void printSanChuan(bool isGan);
	void duanKe();

private:
	int walk(int start,int end);
	int tianpan[12];
	int kelow[4];
	int kehigh[4];
	int sanchuan[3];

	int month;
	int time;
	int riGan;
	int riZhi;

	int ike;
	int izei;
	int ike_he;
	int izei_he;
};
