#include "JinKouJue.h"
#include "Month.h"
#include "Ganzhi.h"
#include "Gan_Zhi.h"
#include "ShenSha.h"

#include <iostream>
using namespace std;

JinKouJue::JinKouJue(Gan_Zhi* pYear,Gan_Zhi* pMonth,Gan_Zhi* pDay,Gan_Zhi* pHour,DiZhi* pDiFen)
{
	this->pYear = pYear;
	this->pMonth = pMonth;
	this->pDay = pDay;
	this->pHour = pHour;
	this->pDiFen = pDiFen;

	this->pYueJiang = Month::buildZhi(Month::getYueJiang(this->pMonth->pDZ)-this->pHour->pDZ->getDzid()+this->pDiFen->getDzid());

	bool isDay = pHour->pDZ->getDzid()<DiZhi::DZyou && pHour->pDZ->getDzid()>=DiZhi::DZmao;

	//cout<<"[debug]isDay="<<isDay<<endl;

	this->pGuiShen = new GuiShen(pDay->pTG,isDay,pDiFen);

	pRenYuan = Month::wuZiYuanDu(pDay->pTG,pDiFen);

	pShenGan = Month::wuZiYuanDu(pDay->pTG,this->pGuiShen->pDZ);
	pJiangGan = Month::wuZiYuanDu(pDay->pTG,this->pYueJiang);

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

	Xing** pXings = new Xing*[4];
	//�ˣ����£���
	pXings[0] = pRenYuan->buildXing();
	pXings[1] = pGuiShen->pXing;
	pXings[2] = pYueJiang->buildXing();
	pXings[3] = pDiFen->buildXing();

	Xing* pYongShenXing = bYongShenIsJiang? pXings[2] : pXings[1];

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
		cout<<"�ɿ˷�Ϊ�޶�"<<endl;
	//3.��˽�Ϊ����
	if(pGuiShen->pDZ->ke(pYueJiang))
		cout<<"��˽�Ϊ����"<<endl;
	//4.���˸�Ϊ��
	if(pDiFen->ke(pRenYuan))
		cout<<"���˸�Ϊ��"<<endl;
	//5.��˸�Ϊ�ٶ�
	if(pGuiShen->pDZ->ke(pRenYuan))
		cout<<"��˸�Ϊ�ٶ�"<<endl;
	
	//�ж�����
	//1.������Ϊ��ĸ��
	if(pDiFen->sheng(pRenYuan))
		cout<<"������Ϊ��ĸ��"<<endl;
	//2.������Ϊ���ﶯ
	if(pRenYuan->sheng(pDiFen))
		cout<<"������Ϊ���ﶯ"<<endl;
	//3.�ɷ�ͬ�ֵܶ�
	if(pRenYuan->getXing() == pDiFen->getXing())
		cout<<"�ɷ�ͬ�ֵܶ�"<<endl;

	shensha();

	delete pXings;
	pXings = NULL;
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
	if(pDiFen->getDzid() == DiZhi::DZzi || pGuiShen->pDZ->getDzid() == DiZhi::DZzi ||pYueJiang->getDzid() == DiZhi::DZzi)
	{
		cout<<"���м������������ȥ�����ʧ���"<<endl;
	}
	//4.���
	if(ShenSha::isTianDe(pMonth->pDZ,pDiFen))
	{
		cout<<"�ط���£����������ǻ������׻���Σ�ð���"<<endl;
	}
	else if(ShenSha::isTianDe(pMonth->pDZ,pYueJiang))
	{
		cout<<"�½���£����������ǻ������׻���Σ�ð���"<<endl;
	}
	else if(ShenSha::isTianDe(pMonth->pDZ,pJiangGan))
	{
		cout<<"�½�����£����������ǻ������׻���Σ�ð���"<<endl;
	}
	else if(ShenSha::isTianDe(pMonth->pDZ,pRenYuan))
	{
		cout<<"��Ԫ��£����������ǻ������׻���Σ�ð���"<<endl;
	}
	else if(ShenSha::isTianDe(pMonth->pDZ,pGuiShen->pDZ))
	{
		cout<<"������£����������ǻ������׻���Σ�ð���"<<endl;
	}
	else if(ShenSha::isTianDe(pMonth->pDZ,pShenGan))
	{
		cout<<"�������£����������ǻ������׻���Σ�ð���"<<endl;
	}
	//5.�µ�
	if(ShenSha::isYueDe(pMonth->pDZ,pRenYuan))
	{
		cout<<"��Ԫ�µ£��µ����������������˳���м��죬������ɷ��������ʧ�����׻��⣬�ü�������"<<endl;
	}
	else if(ShenSha::isYueDe(pMonth->pDZ,pJiangGan))
	{
		cout<<"�����µ£��µ����������������˳���м��죬������ɷ��������ʧ�����׻��⣬�ü�������"<<endl;
	}
	else if(ShenSha::isYueDe(pMonth->pDZ,pShenGan))
	{
		cout<<"����µ£��µ����������������˳���м��죬������ɷ��������ʧ�����׻��⣬�ü�������"<<endl;
	}
}
