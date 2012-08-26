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

#include "Gua.h"
#include "QiMenDunJia.h"

#include <iostream>

#include <boost/smart_ptr.hpp>
#include <boost/make_shared.hpp>

using namespace std;

using boost::make_shared;

int main(int argc, char* argv[])
{
	boost::shared_ptr<Xing> xings[5];

	xings[0] = boost::make_shared<Jin>();
	xings[1] = boost::make_shared<Mu>();
	xings[2] = boost::make_shared<Shui>();
	xings[3] = boost::make_shared<Tu>();
	xings[4] = boost::make_shared<Huo>();

	for(int i=0;i<5;i++){
		for (int j=0;j<5;j++){
			xings[i]->sheng(xings[j]);
			xings[i]->ke(xings[j]);
		}
	}

	boost::shared_ptr<DiZhi> dzs[12];

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

	LiuRen* plr3 = new LiuRen(10, DZsi, TGren, DZxu);
	plr3->diPan();
	plr3->tianPan();
	plr3->siKe();
	plr3->sanChuan();
	plr3->duanKe();

	//比用法

	LiuRen* plr4 = new LiuRen(4, DZwei, TGjia, DZxu);
	plr4->diPan();
	plr4->tianPan();
	plr4->siKe();
	plr4->sanChuan();
	plr4->duanKe();

	LiuRen* plr5 = new LiuRen(9, DZhai, TGxin, DZhai);
	plr5->diPan();
	plr5->tianPan();
	plr5->siKe();
	plr5->sanChuan();
	plr5->duanKe();

	//涉害法
	LiuRen* plr6 = new LiuRen(1, DZchou, TGding, DZmao);
	plr6->diPan();
	plr6->tianPan();
	plr6->siKe();
	plr6->sanChuan();
	plr6->duanKe();

	boost::shared_ptr<LiuRen> plr7(new LiuRen(4, DZxu, TGgeng, DZzi));
	plr7->diPan();
	plr7->tianPan();
	plr7->siKe();
	plr7->sanChuan();
	plr7->duanKe();

	//见机格
	boost::shared_ptr<LiuRen> plr8(new LiuRen(DZshen+1,DZyou,TGji,DZhai));
	plr8->diPan();
	plr8->tianPan();
	plr8->siKe();
	plr8->sanChuan();
	plr8->duanKe();

	//昂星法 阳
	boost::shared_ptr<LiuRen> plr9 = boost::make_shared<LiuRen>(
		Month::getMonthByYueJiang(DZwu),DZyin,TGwu,DZyin);
	plr9->doAll();

	boost::shared_ptr<LiuRen> plr10 = boost::make_shared<LiuRen>(
		Month::getMonthByYueJiang(DZhai),DZzi,TGyi,DZwei);
	plr10->doAll();

	//杨春义讲座涉害法例
	boost::shared_ptr<LiuRen> plr_ycy1 = boost::make_shared<LiuRen>(
		Month::getMonthByYueJiang(DZhai),DZmao,TGjia,DZchen);
	plr_ycy1->doAll();

	boost::shared_ptr<LiuRen> plr_ycy2 = boost::make_shared<LiuRen>(
		6,DZhai,TGbing,DZzi);
	plr_ycy2->doAll();

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

	boost::shared_ptr<JinKouJue> pJKJ = boost::make_shared<JinKouJue>(boost::make_shared<Gan_Zhi>(TGwu, DZyin),
		boost::make_shared<Gan_Zhi>(TGren, DZxu),
		boost::make_shared<Gan_Zhi>(TGgeng, DZyin),
		boost::make_shared<Gan_Zhi>(TGren, DZwu),
		Month::buildZhi(DZshen));

#if 0
	JinKouJue* pJKJ2 = new JinKouJue(
		new Gan_Zhi(TGding, DZhai),
		new Gan_Zhi(TGgui, DZmao),
		new Gan_Zhi(TGding, DZmao),
		new Gan_Zhi(TGyi, DZsi),
		Month::buildZhi(DZyou));

	JinKouJue* pJKJ3 = new JinKouJue(
		new Gan_Zhi(TGwu, DZyin),
		new Gan_Zhi(TGxin, DZyou),
		new Gan_Zhi(TGbing, DZxu),
		new Gan_Zhi(TGyi, DZwei),
		Month::buildZhi(DZzi));

	JinKouJue* pJKJ4 = new JinKouJue(
		new Gan_Zhi(TGwu, DZyin),
		new Gan_Zhi(TGbing, DZchen),
		new Gan_Zhi(TGwu, DZxu),
		new Gan_Zhi(TGgui, DZhai),
		Month::buildZhi(DZwu));

	JinKouJue* pJKJ5 = new JinKouJue(
		new Gan_Zhi(TGding, DZchou),
		new Gan_Zhi(TGgui, DZmao),
		new Gan_Zhi(TGji, DZwei),
		new Gan_Zhi(TGyi, DZsi),
		Month::buildZhi(DZshen));

	JinKouJue* pJKJ6 = new JinKouJue(
		new Gan_Zhi(TGwu, DZyin),
		new Gan_Zhi(TGbing, DZchen),
		new Gan_Zhi(TGding, DZhai),
		new Gan_Zhi(TGjia, DZchen),
		Month::buildZhi(DZmao));

	JinKouJue* pJKJ7 = new JinKouJue(
		new Gan_Zhi(TGjia, DZxu),
		new Gan_Zhi(TGgui, DZyou),
		new Gan_Zhi(TGgeng, DZxu),
		new Gan_Zhi(TGbing, DZzi),
		Month::buildZhi(DZhai));

	JinKouJue* pJKJ8 = new JinKouJue(
		new Gan_Zhi(TGjia, DZxu),
		new Gan_Zhi(TGbing, DZzi),
		new Gan_Zhi(TGji, DZsi),
		new Gan_Zhi(TGji, DZsi),
		Month::buildZhi(DZyin));

	JinKouJue* pJKJ9 = new JinKouJue(
		new Gan_Zhi(TGyi, DZhai),
		new Gan_Zhi(TGgeng, DZchen),
		new Gan_Zhi(TGgeng, DZwu),
		new Gan_Zhi(TGgui, DZwei),
		Month::buildZhi(DZwu));

	JinKouJue* pJKJ_11_1 = new JinKouJue(
		new Gan_Zhi(TGbing, DZzi),
		new Gan_Zhi(TGxin, DZchou),
		new Gan_Zhi(TGding, DZsi),
		new Gan_Zhi(TGgui, DZmao),
		Month::buildZhi(DZwu));
#endif

	pJKJ->show();
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

	cout<<"...经典例..."<<endl;

	QiMenDunJia* pQM3 = new QiMenDunJia(JQYuShui,ShangYuan,boost::make_shared<Gan_Zhi>(TGxin, DZsi));
	//QiMenDunJia::printDiPan();
	pQM3->printDunJu();
			
	cin.get();

	return 0;
}
