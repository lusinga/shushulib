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

	cout<<this->pYear->getName()<<"��"<<this->pMonth->getName()<<"��"<<this->pDay->getName()<<"��"<<this->pHour->getName()<<"ʱ"<<endl;
	cout<<"��Ԫ��"<<this->pRenYuan->getName()<<endl;
	cout<<"����"<<pShenGan->getName()<<this->pGuiShen->getName()<<endl;
	cout<<"�½���"<<pJiangGan->getName()<<this->pYueJiang->getName()<<"("<<parseYueJiangName()<<")"<<endl;
	cout<<"�ط֣�"<<this->pDiFen->getName()<<endl;

	duanKe();

	cout<<"=================================================="<<endl;
}

string JinKouJue::parseYueJiangName()
{
	string name[] = {"����","�ӿ�","�ӿ�","����","С��","ʤ��","̫��","���","̫��","����","��","���"};
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
		cout<<"�����������Խ�Ϊ�ã������������ؿ�ʼ�򹫿���չ����������Ů��ת�����ӻ�������ת��Ů�ӣ����忪ʼ�����������ط�չ�����²��ɲ�֮������"<<endl;
		bYongShenIsJiang = true;
		break;
	case 1:
		cout<<"����Ϊ�ã��������С������������淽��չ��ǰ;������"<<endl;
		if (this->pYueJiang->getDzid() % 2 == 0)
		{
			//��������������Ϊ�ü��Խ�Ϊ�á�
			bYongShenIsJiang = true;
		}
		else
		{
			bYongShenIsJiang = false;
		}
		break;
	case 2:
		cout<<"�����������Խ�Ϊ�ã����ﻹ��̫���ʻ������¼���Ů���������ײ���������λ��Ͼ��ϡ�"<<endl;
		bYongShenIsJiang = false;
		break;
	case 3:
		cout<<"����Ϊ�ã�������Ů���������򷴷���չ��ǰ;������"<<endl;
		if (this->pYueJiang->getDzid() % 2 != 0)
		{
			//��������������Ϊ�ü��Խ�Ϊ�á�
			bYongShenIsJiang = true;
		}
		else
		{
			bYongShenIsJiang = false;
		}
		break;
	case 4:
		cout<<"��������������Ϊ�á���λ��������������������ת˥�����忪ʼ�������ķ��棬�������ؿ�ʼ���ӣ����忪ʼ���ɣ�����תΪŮ������ŮתΪ�С��紦��ɽ�Ķ��壬���·�չ���ڱ�Ȼ�����������ٲ��׳١�"<<endl;
		bYongShenIsJiang = false;
		break;
	default:
		cout<<"���������ˡ�"<<endl;
		break;
	}

	if(bYongShenIsJiang)
	{
		cout<<"�Խ�Ϊ����"<<endl;
	}
	else
	{
		cout<<"����Ϊ����"<<endl;
	}

	shared_ptr<Xing> pXings[4];
	//�ˣ����£���
	pXings[0] = pRenYuan->buildXing();
	pXings[1] = pGuiShen->pXing;
	pXings[2] = pYueJiang->buildXing();
	pXings[3] = pDiFen->buildXing();

	shared_ptr<Xing> pYongShenXing = bYongShenIsJiang? pXings[2] : pXings[1];

	int state = Xing::getState(pYongShenXing,pXings,4);
	switch(state)
	{
	case Xing::WANG:
		cout<<"������"<<endl;
		break;
	case Xing::XIANG:
		cout<<"������"<<endl;
		break;
	case Xing::XIU:
		cout<<"������"<<endl;
		break;
	case Xing::QIU:
		cout<<"������"<<endl;
		break;
	case Xing::SI:
		cout<<"������"<<endl;
		break;
	case Xing::ZHEFU:
		cout<<"�����ݷ�"<<endl;
		break;
	}

	if(pDay->isXunKong(pYueJiang))
		cout<<"�½�Ѯ��"<<endl;

	if(pDay->isXunKong(pGuiShen->pDZ))
		cout<<"����Ѯ��"<<endl;

	if (pDay->isXunKong(pYueJiang) ||pDay->isXunKong(pGuiShen->pDZ))
	{
		cout<<"1.�¼���٣����²���ʵ������թ��Ϊ��\n2.���������в�ʵ�����������ʡ�"<<endl;
		if(state == Xing::WANG || state == Xing::XIANG)
		{
			cout<<"3.���±�Ѯ�в��ɣ���Ѯ����ϣ����"<<endl;
			cout<<"��Ѯ����Ҫ"<<10 - pDay->pTG->getTgid()<<"�졣"<<endl;
		}
	}

	if(pDay->isSiDaKongWang(pRenYuan->getXing()) ||pDay->isSiDaKongWang(pGuiShen->pDZ->getXing()) || 
		pDay->isSiDaKongWang(pYueJiang->getXing()) || pDay->isSiDaKongWang(pDiFen->getXing()))
	{
		cout<<"���Ĵ���������ײ��ɡ�"<<endl;
		cout<<"�������ڴ���ɡ�"<<endl;
	}

	//�ж��嶯
	//1.������Ϊ�ƶ�
	if(pYueJiang->ke(pGuiShen->pDZ))
		cout<<"������Ϊ�ƶ�\n������������ʹ����������ʻ���������һ���������ʲ������мҳ��в���"<<endl;
	//2.�ɿ˷�Ϊ�޶�
	if(pRenYuan->ke(pDiFen))
		cout<<"�ɿ˷�Ϊ�޶�\n�ʻ���������֮���ʹ��ʲƶ�������"<<endl;
	//3.��˽�Ϊ����
	if(pGuiShen->pDZ->ke(pYueJiang))
		cout<<"��˽�Ϊ����"<<endl;
	//4.���˸�Ϊ��
	if(pDiFen->ke(pRenYuan))
		cout<<"���˸�Ϊ��\n�ʹ�������־���Զ��������ı������ƣ���������ơ�"<<endl;
	//5.��˸�Ϊ�ٶ�
	if(pGuiShen->pDZ->ke(pRenYuan))
		cout<<"��˸�Ϊ�ٶ�"<<endl;
	
	//�ж�����
	//1.������Ϊ��ĸ��
	if(pDiFen->sheng(pRenYuan))
		cout<<"������Ϊ��ĸ��\n��ӡ��֮�£���������١��������顣"<<endl;
	//2.������Ϊ���ﶯ
	if(pRenYuan->sheng(pDiFen))
		cout<<"������Ϊ���ﶯ\n�������﷽����¡�"<<endl;
	//3.�ɷ�ͬ�ֵܶ�
	if(pRenYuan->getXing() == pDiFen->getXing())
		cout<<"�ɷ�ͬ�ֵܶ�"<<endl;

	shensha();

}

void JinKouJue::shensha()
{
	//1. ��Ԫ����
	if(pRenYuan->getTgid() == TianGan::TGjia)
	{
		cout<<"��Ԫ���ס�����ϲ��ͻ���ϲ��֮�£��Ʋ���ְ����֮�¡����¼���"<<endl;
	}
	//2.��Ԫ����
	if(pRenYuan->getTgid() == TianGan::TGding)
	{
		cout<<"��Ԫ�����������������£����в����������ǳ���������񾭲���"<<endl;
	}
	//3.���(���м���ˮ)
	BOOST_FOREACH(shared_ptr<DiZhi> pDZ, zhis)
	{
		if(pDZ->getDzid() ==DiZhi::DZzi)
		{
			cout<<"���м������������ȥ�����ʧ���"<<endl;
		}
	}
	//4.���
	BOOST_FOREACH(shared_ptr<DiZhi> pDZ, zhis)
	{
		if(ShenSha::isTianDe(pMonth->pDZ,pDZ))
		{
			cout<<"���������ǻ������׻���Σ�ð���"<<endl;
		}
	}

	BOOST_FOREACH(shared_ptr<TianGan> pTG, gans)
	{
		if(ShenSha::isTianDe(pMonth->pDZ,pTG))
		{
			cout<<"���������ǻ������׻���Σ�ð���"<<endl;
		}
	}
	
	//5.�µ�
	BOOST_FOREACH(shared_ptr<TianGan> pTG, gans)
	{
		if(ShenSha::isYueDe(pMonth->pDZ,pTG->getTgid()))
		{
			cout<<"�µ����������������˳���м��죬������ɷ��������ʧ�����׻��⣬�ü�������"<<endl;
		}
	}
	//6.��º�
	BOOST_FOREACH(shared_ptr<TianGan> pTG, gans)
	{
		if(ShenSha::isTianDeHe(pMonth->pDZ,pTG))
		{
			cout<<"��º�������ǻ������׻���Σ�ð���ϲ��̶��Դ�����¡�"<<endl;
		}
	}
	//7.�µº�
	BOOST_FOREACH(shared_ptr<TianGan> pTG, gans)
	{
		shared_ptr<TianGan> pTGHe = Month::buildGan(pTG->getHe());
		if (ShenSha::isYueDe(pMonth->pDZ,pTGHe->getTgid()))
		{
			cout<<"�µº����������������˳���м��죬������ɷ��������ʧ�����׻��⣬�ü����������Ǽ���̶Ȳ����µ¡�"<<endl;
		}
	}
	//8.����
	BOOST_FOREACH(shared_ptr<DiZhi> pDZ, zhis)
	{
		if(ShenSha::isTianMa(pMonth->pDZ->getMonth(),pDZ->getDzid()))
		{
			cout<<"�����������Ѹ�١�"<<endl;
		}
	}

	//9.����
	BOOST_FOREACH(shared_ptr<DiZhi> pDZ, zhis)
	{
		if(ShenSha::isDuoMa(pDay->pDZ->getDzid(),pDZ->getDzid()))
		{
			cout<<"�����������Ѹ�١�"<<endl;
		}
	}
	//10.��ɷ
	BOOST_FOREACH(shared_ptr<DiZhi> pDZ, zhis)
	{
		if(ShenSha::isJieSha(pDay->pDZ->getDzid(),pDZ->getDzid()))
		{
			cout<<"��ɷ����Ȩ���֣����������ͷ�죬�ݶ����ڻ�ָ�ӣ����������й�˾��"<<endl;
		}
	}
	//11.������ɷ
	//12.��ϲ
	//13.»��
	//14.��
	//15.����
	//16.ɥ�ţ�����
	//17.����
	//18.ɥ��
	//19.����
	//20.����
	//21.��ɷ
	//22.����
	//23.����
	//24.ÿ������������
	//25.��ҽ
	//26.��ҽ
	//27.����
	//28.Ѯ��
	//29.ɥ��
	//30.����������ʱ
	//31.���޵���
	//32.�ظ���
	//33.�İ�
	//34.�����ľ�
	//35.����
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
			cout<<"���������棬�������ˣ����¼�������ٵù٣���Ƶòƣ��������ӣ������и����������������º�ͨ��"<<endl;
			//PRINT_ELEMENTS(ganset, "��ɱ�");
			//PRINT_ELEMENTS(sanqi,"�����");
		}
	}
}
