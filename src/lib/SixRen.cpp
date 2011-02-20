// SixRen.cpp : Defines the entry point for the console application.
//

#include "Xing.h"
#include "Jin.h"
#include "Shui.h"
#include "Mu.h"
#include "Huo.h"
#include "Tu.h"

#include "month.h"
#include "liuren.h"

#include "Gan_Zhi.h"
#include "JinKouJue.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	Xing* xings[5];

	xings[0] = new Jin();
	xings[1] = new Mu();
	xings[2] = new Shui();
	xings[3] = new Tu();
	xings[4] = new Huo();

	for(int i=0;i<5;i++){
		for (int j=0;j<5;j++){
			xings[i]->sheng(xings[j]);
			xings[i]->ke(xings[j]);
		}
	}

	DiZhi* dzs[12];

	for(int i=0;i<12;i++)
	{
		dzs[i] = Month::buildZhi(i);
	}

	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			dzs[i]->he(dzs[j]);
			dzs[i]->chong(dzs[j]);
		}
	}

	LiuRen* plr = new LiuRen(1,3, 0, 0);
	plr->diPan();
	plr->tianPan();
	plr->siKe();
	plr->sanChuan();
	plr->duanKe();

	LiuRen* plr2 = new LiuRen(3, 6, 0, 4);
	plr2->diPan();
	plr2->tianPan();
	plr2->siKe();
	plr2->sanChuan();
	plr2->duanKe();

	LiuRen* plr3 = new LiuRen(10, DiZhi::DZsi, TianGan::TGren, DiZhi::DZxu);
	plr3->diPan();
	plr3->tianPan();
	plr3->siKe();
	plr3->sanChuan();
	plr3->duanKe();

	//比用法

	LiuRen* plr4 = new LiuRen(4, DiZhi::DZwei, TianGan::TGjia, DiZhi::DZxu);
	plr4->diPan();
	plr4->tianPan();
	plr4->siKe();
	plr4->sanChuan();
	plr4->duanKe();

	LiuRen* plr5 = new LiuRen(9, DiZhi::DZhai, TianGan::TGxin, DiZhi::DZhai);
	plr5->diPan();
	plr5->tianPan();
	plr5->siKe();
	plr5->sanChuan();
	plr5->duanKe();

	//涉害法
	LiuRen* plr6 = new LiuRen(1, DiZhi::DZchou, TianGan::TGding, DiZhi::DZmao);
	plr6->diPan();
	plr6->tianPan();
	plr6->siKe();
	plr6->sanChuan();
	plr6->duanKe();

	LiuRen* plr7 = new LiuRen(4, DiZhi::DZxu, TianGan::TGgeng, DiZhi::DZzi);
	plr7->diPan();
	plr7->tianPan();
	plr7->siKe();
	plr7->sanChuan();
	plr7->duanKe();

	Gan_Zhi* pGZ = new Gan_Zhi(0,0);
	cout<<pGZ->getName()<<endl;

	JinKouJue* pJKJ = new JinKouJue(new Gan_Zhi(TianGan::TGwu, DiZhi::DZyin),
		new Gan_Zhi(TianGan::TGren, DiZhi::DZxu),
		new Gan_Zhi(TianGan::TGgeng, DiZhi::DZyin),
		new Gan_Zhi(TianGan::TGren, DiZhi::DZwu),
		Month::buildZhi(DiZhi::DZshen));

	JinKouJue* pJKJ2 = new JinKouJue(
		new Gan_Zhi(TianGan::TGding, DiZhi::DZhai),
		new Gan_Zhi(TianGan::TGgui, DiZhi::DZmao),
		new Gan_Zhi(TianGan::TGding, DiZhi::DZmao),
		new Gan_Zhi(TianGan::TGyi, DiZhi::DZsi),
		Month::buildZhi(DiZhi::DZyou));

	JinKouJue* pJKJ3 = new JinKouJue(
		new Gan_Zhi(TianGan::TGwu, DiZhi::DZyin),
		new Gan_Zhi(TianGan::TGxin, DiZhi::DZyou),
		new Gan_Zhi(TianGan::TGbing, DiZhi::DZxu),
		new Gan_Zhi(TianGan::TGyi, DiZhi::DZwei),
		Month::buildZhi(DiZhi::DZzi));

	pJKJ->show();
	pJKJ2->show();
	pJKJ3->show();

	Xing* pXings[] = {new Jin(), new Mu(), new Shui(), new Huo()};
	int index = Xing::whichWang(pXings,4);
	cout<<"The wang index is"<<index<<endl;
	
	cin.get();
	
	return 0;
}
