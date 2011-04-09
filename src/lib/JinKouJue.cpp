#include "JinKouJue.h"
#include "Month.h"
#include "Ganzhi.h"
#include "Gan_Zhi.h"
#include "ShenSha.h"

#include <iostream>
#include <boost/foreach.hpp>
#include <vector>
#include <memory>
#include <set>
#include <algorithm>

#include <boost/make_shared.hpp>

using namespace std;

JinKouJue::JinKouJue(shared_ptr<Gan_Zhi> pYear,shared_ptr<Gan_Zhi> pMonth,
	shared_ptr<Gan_Zhi> pDay,shared_ptr<Gan_Zhi> pHour,shared_ptr<DiZhi> pDiFen)
{
	this->pYear = pYear;
	this->pMonth = pMonth;
	this->pDay = pDay;
	this->pHour = pHour;
	this->pDiFen = pDiFen;

	this->pYueJiang = Month::buildZhi(Month::getYueJiang(this->pMonth->pDZ)-this->pHour->pDZ->getDzid()+this->pDiFen->getDzid());

	bool isDay = pHour->pDZ->getDzid()<DiZhi::DZyou && pHour->pDZ->getDzid()>=DiZhi::DZmao;

	//cout<<"[debug]isDay="<<isDay<<endl;

	this->pGuiShen = make_shared<GuiShen>(pDay->pTG,isDay,pDiFen);

	pRenYuan = Month::wuZiYuanDu(pDay->pTG,pDiFen);

	pShenGan = Month::wuZiYuanDu(pDay->pTG,this->pGuiShen->pDZ);
	pJiangGan = Month::wuZiYuanDu(pDay->pTG,this->pYueJiang);

	gans.push_back(pRenYuan);
	gans.push_back(pShenGan);
	gans.push_back(pJiangGan);

	zhis.push_back(pDiFen);
	zhis.push_back(pYueJiang);
	zhis.push_back(pGuiShen->pDZ);

	sizhu.push_back(pYear);
	sizhu.push_back(pMonth);
	sizhu.push_back(pDay);
	sizhu.push_back(pHour);
}

JinKouJue::~JinKouJue(void)
{
}

void JinKouJue::show()
{

	cout<<this->pYear->getName()<<"年"<<this->pMonth->getName()<<"月"<<this->pDay->getName()<<"日"<<this->pHour->getName()<<"时"<<endl;
	cout<<"人元："<<this->pRenYuan->getName()<<endl;
	cout<<"贵神："<<pShenGan->getName()<<this->pGuiShen->getName()<<endl;
	cout<<"月将："<<pJiangGan->getName()<<this->pYueJiang->getName()<<"("<<parseYueJiangName()<<")"<<endl;
	cout<<"地分："<<this->pDiFen->getName()<<endl;

	duanKe();

	cout<<"=================================================="<<endl;
}

string JinKouJue::parseYueJiangName()
{
	string name[] = {"登明","河魁","从魁","传送","小吉","胜光","太乙","天罡","太冲","功曹","大吉","神后"};
	return name[11-this->pYueJiang->getDzid()];
}

void JinKouJue::duanKe()
{
	int iYang = 0;
	if(this->pRenYuan->getTgid() % 2 == 0) 
		iYang++;
	if(this->pGuiShen->pYinYang->isYang()) 
		iYang++;
	if(this->pYueJiang->getDzid() % 2 == 0)
		iYang++;
	if(this->pDiFen->getDzid() % 2 == 0)
		iYang++;
	
	switch(iYang)
	{
	case 0:
		cout<<"纯阴反阳，以将为用，主事体由隐秘开始向公开发展。问事体由女子转向男子或由男子转向女子，事体开始向有利的因素发展，做事不可操之过急。"<<endl;
		bYongShenIsJiang = true;
		break;
	case 1:
		cout<<"以阳为用，主事在男。事物在向正面方向发展，前途光明。"<<endl;
		if (this->pYueJiang->getDzid() % 2 == 0)
		{
			//将是阳，则以阳为用即以将为用。
			bYongShenIsJiang = true;
		}
		else
		{
			bYongShenIsJiang = false;
		}
		break;
	case 2:
		cout<<"二阴二阳，以将为用，事物还不太明朗化，问事件男女不明，吉凶不定。看四位配合决断。"<<endl;
		bYongShenIsJiang = false;
		break;
	case 3:
		cout<<"以阴为用，主事在女。事物正向反方向发展，前途不明。"<<endl;
		if (this->pYueJiang->getDzid() % 2 != 0)
		{
			//将是阴，则以阴为用即以将为用。
			bYongShenIsJiang = true;
		}
		else
		{
			bYongShenIsJiang = false;
		}
		break;
	case 4:
		cout<<"纯阳反阴，以神为用。四位纯阳，阳气过旺。旺极转衰，事体开始走向它的反面，不利因素开始增加，事体开始过渡，由男转为女，或由女转为男。如处在山的顶峰，向下发展势在必然。故做事易速不易迟。"<<endl;
		bYongShenIsJiang = false;
		break;
	default:
		cout<<"阴阳错乱了。"<<endl;
		break;
	}

	if(bYongShenIsJiang)
	{
		cout<<"以将为用神"<<endl;
	}
	else
	{
		cout<<"以神为用神"<<endl;
	}

	shared_ptr<Xing> pXings[4];
	//人，贵，月，地
	pXings[0] = pRenYuan->buildXing();
	pXings[1] = pGuiShen->pXing;
	pXings[2] = pYueJiang->buildXing();
	pXings[3] = pDiFen->buildXing();

	shared_ptr<Xing> pYongShenXing = bYongShenIsJiang? pXings[2] : pXings[1];

	int state = Xing::getState(pYongShenXing,pXings,4);
	switch(state)
	{
	case Xing::WANG:
		cout<<"用神旺"<<endl;
		break;
	case Xing::XIANG:
		cout<<"用神相"<<endl;
		break;
	case Xing::XIU:
		cout<<"用神休"<<endl;
		break;
	case Xing::QIU:
		cout<<"用神囚"<<endl;
		break;
	case Xing::SI:
		cout<<"用神死"<<endl;
		break;
	case Xing::ZHEFU:
		cout<<"用神蛰伏"<<endl;
		break;
	}

	if(pDay->isXunKong(pYueJiang))
		cout<<"月将旬空"<<endl;

	if(pDay->isXunKong(pGuiShen->pDZ))
		cout<<"贵神旬空"<<endl;

	if (pDay->isXunKong(pYueJiang) ||pDay->isXunKong(pGuiShen->pDZ))
	{
		cout<<"1.事件虚假，此事不真实，有欺诈行为。\n2.问事人心中不实，非真心求问。"<<endl;
		if(state == Xing::WANG || state == Xing::XIANG)
		{
			cout<<"3.此事本旬中不成，出旬可有希望。"<<endl;
			cout<<"出旬还需要"<<10 - pDay->pTG->getTgid()<<"天。"<<endl;
		}
	}

	if(pDay->isSiDaKongWang(pRenYuan->getXing()) ||pDay->isSiDaKongWang(pGuiShen->pDZ->getXing()) || 
		pDay->isSiDaKongWang(pYueJiang->getXing()) || pDay->isSiDaKongWang(pDiFen->getXing()))
	{
		cout<<"遇四大空亡，吉凶不成。"<<endl;
		cout<<"出空日期待完成。"<<endl;
	}

	//判断五动
	//1.将克神为财动
	if(pYueJiang->ke(pGuiShen->pDZ))
		cout<<"将克神为财动\n主求财有利。问官主不利。问婚姻主本人一生财旺。问病主家中家长有病。"<<endl;
	//2.干克方为妻动
	if(pRenYuan->ke(pDiFen))
		cout<<"干克方为妻动\n问婚姻主不成之象。问官问财都不利。"<<endl;
	//3.神克将为贼动
	if(pGuiShen->pDZ->ke(pYueJiang))
		cout<<"神克将为贼动"<<endl;
	//4.方克干为鬼动
	if(pDiFen->ke(pRenYuan))
		cout<<"方克干为鬼动\n问官主本人志向高远，在外求谋。问求财，主在外求财。"<<endl;
	//5.神克干为官动
	if(pGuiShen->pDZ->ke(pRenYuan))
		cout<<"神克干为官动"<<endl;
	
	//判断三动
	//1.方生干为父母动
	if(pDiFen->sheng(pRenYuan))
		cout<<"方生干为父母动\n主印授之事，故利于求官。又主文书。"<<endl;
	//2.干生方为子孙动
	if(pRenYuan->sheng(pDiFen))
		cout<<"干生方为子孙动\n多主子孙方面的事。"<<endl;
	//3.干方同兄弟动
	if(pRenYuan->getXing() == pDiFen->getXing())
		cout<<"干方同兄弟动"<<endl;

	shensha();

}

void JinKouJue::shensha()
{
	//1. 人元见甲
	if(pRenYuan->getTgid() == TianGan::TGjia)
	{
		cout<<"人元见甲。甲主喜庆和婚姻喜美之事，财帛官职文书之事。主事吉。"<<endl;
	}
	//2.人元见丁
	if(pRenYuan->getTgid() == TianGan::TGding)
	{
		cout<<"人元见丁。丁火主惊恐事，家中不安，疾病忧愁，损伤六畜，神经病人"<<endl;
	}
	//3.天盗(课中见子水)
	BOOST_FOREACH(shared_ptr<DiZhi> pDZ, zhis)
	{
		if(pDZ->getDzid() ==DiZhi::DZzi)
		{
			cout<<"课中见天盗，被贼盗去财物，丢失宝物。"<<endl;
		}
	}
	//4.天德
	BOOST_FOREACH(shared_ptr<DiZhi> pDZ, zhis)
	{
		if(ShenSha::isTianDe(pMonth->pDZ,pDZ))
		{
			cout<<"天德入课无忧祸，逢凶化吉危得安。"<<endl;
		}
	}

	BOOST_FOREACH(shared_ptr<TianGan> pTG, gans)
	{
		if(ShenSha::isTianDe(pMonth->pDZ,pTG))
		{
			cout<<"天德入课无忧祸，逢凶化吉危得安。"<<endl;
		}
	}
	
	//5.月德
	BOOST_FOREACH(shared_ptr<TianGan> pTG, gans)
	{
		if(ShenSha::isYueDe(pMonth->pDZ,pTG->getTgid()))
		{
			cout<<"月德入课主和眭，万事顺达有吉庆，化解凶煞，减少损失，逢凶化解，得吉助吉。"<<endl;
		}
	}
	//6.天德合
	BOOST_FOREACH(shared_ptr<TianGan> pTG, gans)
	{
		if(ShenSha::isTianDeHe(pMonth->pDZ,pTG))
		{
			cout<<"天德合入课无忧祸，逢凶化吉危得安，喜庆程度稍次于天德。"<<endl;
		}
	}
	//7.月德合
	BOOST_FOREACH(shared_ptr<TianGan> pTG, gans)
	{
		shared_ptr<TianGan> pTGHe = Month::buildGan(pTG->getHe());
		if (ShenSha::isYueDe(pMonth->pDZ,pTGHe->getTgid()))
		{
			cout<<"月德合入课主和眭，万事顺达有吉庆，化解凶煞，减少损失，逢凶化解，得吉助吉，但是吉庆程度不如月德。"<<endl;
		}
	}
	//8.天马
	BOOST_FOREACH(shared_ptr<DiZhi> pDZ, zhis)
	{
		if(ShenSha::isTianMa(pMonth->pDZ->getMonth(),pDZ->getDzid()))
		{
			cout<<"天马入课主事迅速。"<<endl;
		}
	}

	//9.驿马
	BOOST_FOREACH(shared_ptr<DiZhi> pDZ, zhis)
	{
		if(ShenSha::isDuoMa(pDay->pDZ->getDzid(),pDZ->getDzid()))
		{
			cout<<"驿马入课主事迅速。"<<endl;
		}
	}
	//10.劫煞
	BOOST_FOREACH(shared_ptr<DiZhi> pDZ, zhis)
	{
		if(ShenSha::isJieSha(pDay->pDZ->getDzid(),pDZ->getDzid()))
		{
			cout<<"劫煞君子权在手，政法军令和头领，狠毒服众会指挥，常人凶伤有官司。"<<endl;
		}
	}
	//11.截命灾煞
	//12.天喜
	//13.禄倒
	//14.马倒
	//15.病符
	//16.丧门，吊客
	//17.天赦
	//18.丧车
	//19.四丘
	//20.飞廉
	//21.地煞
	//22.灭门
	//23.往亡
	//24.每月生气、死气
	//25.天医
	//26.地医
	//27.五鬼歌
	//28.旬空
	//29.丧门
	//30.天鬼加年月日时
	//31.天罗地网
	//32.关隔锁
	//33.四败
	//34.课中四绝
	//35.三奇
	set<int> ganset;
	BOOST_FOREACH(shared_ptr<TianGan> pTG, gans)
	{
		ganset.insert(pTG->getTgid());
	}
	BOOST_FOREACH(shared_ptr<Gan_Zhi> pGZ, sizhu)
	{
		ganset.insert(pGZ->pTG->getTgid());
	}
	set<int> tiansanqi;
	set<int> disanqi;
	set<int> rensanqi;
	
	tiansanqi.insert(TianGan::TGjia);
	tiansanqi.insert(TianGan::TGgeng);
	tiansanqi.insert(TianGan::TGwu);

	disanqi.insert(TianGan::TGyi);
	disanqi.insert(TianGan::TGbing);
	disanqi.insert(TianGan::TGding);

	rensanqi.insert(TianGan::TGxin);
	rensanqi.insert(TianGan::TGren);
	rensanqi.insert(TianGan::TGgui);
	
	vector<set<int>> sanqis;
	sanqis.push_back(tiansanqi);
	sanqis.push_back(disanqi);
	sanqis.push_back(rensanqi);

	BOOST_FOREACH(set<int>sanqi, sanqis)
	{
		if(includes(ganset.begin(),ganset.end(),sanqi.begin(),sanqi.end()))
		{
			cout<<"课中遇三奇，利见大人，百事吉昌，求官得官，求财得财，孕生贵子，上下有辅，贵人相助，万事亨通。"<<endl;
			//PRINT_ELEMENTS(ganset, "天干表");
			//PRINT_ELEMENTS(sanqi,"三奇表");
		}
	}
}
