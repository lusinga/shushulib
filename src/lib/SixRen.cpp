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

#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>

using namespace std;

using boost::make_shared;

int main(int argc, char* argv[])
{
	shared_ptr<Xing> xings[5];

	xings[0] = make_shared<Jin>();
	xings[1] = make_shared<Mu>();
	xings[2] = make_shared<Shui>();
	xings[3] = make_shared<Tu>();
	xings[4] = make_shared<Huo>();

	for(int i=0;i<5;i++){
		for (int j=0;j<5;j++){
			xings[i]->sheng(xings[j]);
			xings[i]->ke(xings[j]);
		}
	}

	shared_ptr<DiZhi> dzs[12];

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

	shared_ptr<LiuRen> plr7(new LiuRen(4, DiZhi::DZxu, TianGan::TGgeng, DiZhi::DZzi));
	plr7->diPan();
	plr7->tianPan();
	plr7->siKe();
	plr7->sanChuan();
	plr7->duanKe();

	Gan_Zhi* pGZ = new Gan_Zhi(0,0);
	cout<<pGZ->getName()<<endl;

	//Xing* pXings1[] = {new Jin(), new Mu(), new Shui(), new Huo()};
	//int index = Xing::whichWang(pXings1,4);
	//cout<<"The wang index is "<<index<<endl;

	//Xing* pXings2[] = {new Mu(), new Huo(), new Shui(), new Tu()};
	//index = Xing::whichWang(pXings2,4);
	//cout<<"The wang index is "<<index<<endl;

	//Xing* pXings3[] = {new Jin(), new Mu(), new Huo(), new Tu()};
	//index = Xing::whichWang(pXings3,4);
	//cout<<"The wang index is "<<index<<endl;

	//Xing* pXings4[] = {new Jin(), new Mu(), new Shui(), new Shui()};
	//index = Xing::whichWang(pXings4,4);
	//cout<<"The wang index is "<<index<<endl;

	//Xing* pXings5[] = {new Mu(), new Huo(), new Shui(), new Shui()};
	//index = Xing::whichWang(pXings5,4);
	//cout<<"The wang index is "<<index<<endl;

	//Xing* pXings6[] = {new Tu(), new Huo(), new Mu(), new Tu()};
	//index = Xing::whichWang(pXings6,4);
	//cout<<"The wang index is "<<index<<endl;

	//Xing* pXings7[] = {new Jin(), new Mu(), new Jin(), new Mu()};
	//index = Xing::whichWang(pXings7,4);
	//cout<<"The wang index is "<<index<<endl;

	//Xing* pXings8[] = {new Jin(), new Shui(), new Shui(), new Jin()};
	//index = Xing::whichWang(pXings8,4);
	//cout<<"The wang index is "<<index<<endl;

	//Xing* pXings9[] = {new Tu(), new Tu(), new Huo(), new Huo()};
	//index = Xing::whichWang(pXings9,4);
	//cout<<"The wang index is "<<index<<endl;

	//Xing* pXings10[] = {new Jin(), new Jin(), new Jin(), new Mu()};
	//index = Xing::whichWang(pXings10,4);
	//cout<<"The wang index is "<<index<<endl;

	//Xing* pXings11[] = {new Jin(), new Jin(), new Shui(), new Jin()};
	//index = Xing::whichWang(pXings11,4);
	//cout<<"The wang index is "<<index<<endl;

	//Xing* pXings12[] = {new Tu(), new Shui(), new Shui(), new Shui()};
	//index = Xing::whichWang(pXings12,4);
	//cout<<"The wang index is "<<index<<endl;

	//Xing* pXings13[] = {new Tu(), new Tu(), new Tu(), new Tu()};
	//index = Xing::whichWang(pXings13,4);
	//cout<<"The wang index is "<<index<<endl;

	shared_ptr<JinKouJue> pJKJ = make_shared<JinKouJue>(make_shared<Gan_Zhi>(TianGan::TGwu, DiZhi::DZyin),
		make_shared<Gan_Zhi>(TianGan::TGren, DiZhi::DZxu),
		make_shared<Gan_Zhi>(TianGan::TGgeng, DiZhi::DZyin),
		make_shared<Gan_Zhi>(TianGan::TGren, DiZhi::DZwu),
		Month::buildZhi(DiZhi::DZshen));

#if 0
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

	JinKouJue* pJKJ4 = new JinKouJue(
		new Gan_Zhi(TianGan::TGwu, DiZhi::DZyin),
		new Gan_Zhi(TianGan::TGbing, DiZhi::DZchen),
		new Gan_Zhi(TianGan::TGwu, DiZhi::DZxu),
		new Gan_Zhi(TianGan::TGgui, DiZhi::DZhai),
		Month::buildZhi(DiZhi::DZwu));

	JinKouJue* pJKJ5 = new JinKouJue(
		new Gan_Zhi(TianGan::TGding, DiZhi::DZchou),
		new Gan_Zhi(TianGan::TGgui, DiZhi::DZmao),
		new Gan_Zhi(TianGan::TGji, DiZhi::DZwei),
		new Gan_Zhi(TianGan::TGyi, DiZhi::DZsi),
		Month::buildZhi(DiZhi::DZshen));

	JinKouJue* pJKJ6 = new JinKouJue(
		new Gan_Zhi(TianGan::TGwu, DiZhi::DZyin),
		new Gan_Zhi(TianGan::TGbing, DiZhi::DZchen),
		new Gan_Zhi(TianGan::TGding, DiZhi::DZhai),
		new Gan_Zhi(TianGan::TGjia, DiZhi::DZchen),
		Month::buildZhi(DiZhi::DZmao));

	JinKouJue* pJKJ7 = new JinKouJue(
		new Gan_Zhi(TianGan::TGjia, DiZhi::DZxu),
		new Gan_Zhi(TianGan::TGgui, DiZhi::DZyou),
		new Gan_Zhi(TianGan::TGgeng, DiZhi::DZxu),
		new Gan_Zhi(TianGan::TGbing, DiZhi::DZzi),
		Month::buildZhi(DiZhi::DZhai));

	JinKouJue* pJKJ8 = new JinKouJue(
		new Gan_Zhi(TianGan::TGjia, DiZhi::DZxu),
		new Gan_Zhi(TianGan::TGbing, DiZhi::DZzi),
		new Gan_Zhi(TianGan::TGji, DiZhi::DZsi),
		new Gan_Zhi(TianGan::TGji, DiZhi::DZsi),
		Month::buildZhi(DiZhi::DZyin));

	JinKouJue* pJKJ9 = new JinKouJue(
		new Gan_Zhi(TianGan::TGyi, DiZhi::DZhai),
		new Gan_Zhi(TianGan::TGgeng, DiZhi::DZchen),
		new Gan_Zhi(TianGan::TGgeng, DiZhi::DZwu),
		new Gan_Zhi(TianGan::TGgui, DiZhi::DZwei),
		Month::buildZhi(DiZhi::DZwu));

	JinKouJue* pJKJ_11_1 = new JinKouJue(
		new Gan_Zhi(TianGan::TGbing, DiZhi::DZzi),
		new Gan_Zhi(TianGan::TGxin, DiZhi::DZchou),
		new Gan_Zhi(TianGan::TGding, DiZhi::DZsi),
		new Gan_Zhi(TianGan::TGgui, DiZhi::DZmao),
		Month::buildZhi(DiZhi::DZwu));
#endif
	
	//pJKJ->show();
	//pJKJ2->show();
	//pJKJ3->show();
	//pJKJ4->show();
	//pJKJ5->show();
	//pJKJ6->show();
	////pJKJ7->show();//???
	////pJKJ8->show();//???
	//pJKJ9->show();

	////《金口诀教程》第十一讲 解课分析课例指导
	////例1
	//pJKJ_11_1->show();

	cin.get();
	
	return 0;
}
