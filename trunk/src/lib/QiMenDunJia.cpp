#include "QiMenDunJia.h"
#include "Gua.h"
#include "BaMen.h"
#include "JiuXing.h"
#include "BaZhaShen.h"
#include "QiYi.h"
#include "Tiangan.h"

QiMenDunJia::QiMenDunJia(int jq, int yuan, boost::shared_ptr<Gan_Zhi> pGZ)
{
	this->jieqi = jq;
	int tg = pGZ->getXunShouTianGan();
	cout<<"旬首是："<<Month::buildGan(tg)->getName().c_str()<<endl;
	this->setDunJu();
	shiGan = pGZ->pTG->getTgid();
	shiZhi = pGZ->pDZ->getDzid();
	paiJu(yuan,tg);
}

QiMenDunJia::~QiMenDunJia(void)
{
}

void QiMenDunJia::printDiPan()
{
	for(int i=0;i<9;i++)
	{
		int gua = qiMenDiPan[i];
		cout<<BaGua::getGuaName(gua)->c_str()<<"\t";
		cout<<JiuXing::getXingName(i)->c_str()<<"\t";
		if (i<8) 
		{
			cout<<BaMen::getBaMenName(i)->c_str()<<"\t";
			cout<<BaZhaShen::getShenName(i)->c_str()<<"\t";
		}
		cout<<endl;
	}
}

void QiMenDunJia::printDunJu()
{
	for(int i=0;i<9;i++)
	{
		int gua = qiMenDiPan[i];
		cout<<BaGua::getGuaName(gua)->c_str()<<"\t";
		cout<<JiuXing::getXingName(tianPan2[i].star)->c_str()<<"\t";
		if (i<8) 
		{
			cout<<BaMen::getBaMenName(renPan[i])->c_str()<<"\t";
			cout<<BaZhaShen::getShenName(shenPan2[i])->c_str()<<"\t";
		}
		cout<<TianGan::getQiYiName(tianPan2[i].qiyi)->c_str()<<"\t";
		cout<<endl;
	}
}

void QiMenDunJia::setDunJu()
{
	isYangDun = (this->jieqi < JQXiaZhi && jieqi >= JQDongZhi);

	switch(jieqi)
	{
	//阳遁
	case JQDongZhi:
	case JQJingZhe:
		dunju[0] = 1;
		dunju[1] = 7;
		dunju[2] = 4;
		break;
	case JQXiaoHai:
		dunju[0] = 2;
		dunju[1] = 5;
		dunju[2] = 8;
		break;
	case JQDaHan:
	case JQChunFen:
		dunju[0] = 3;
		dunju[1] = 9;
		dunju[2] = 6;
		break;
	case JQMangZhong:
		dunju[0] = 6;
		dunju[1] = 3;
		dunju[2] = 9;
	break;
	case JQGuYu:
	case JQXiaoMan:
		dunju[0] = 5;
		dunju[1] = 2;
		dunju[2] = 8;
		break;
	case JQLiChun:
		dunju[0] = 8;
		dunju[1] = 5;
		dunju[2] = 2;
		break;
	case JQLiXia:
	case JQQingMing:
		dunju[0] = 4;
		dunju[1] = 1;
		dunju[2] = 7;
		break;
	case JQYuShui:
		dunju[0] = 9;
		dunju[1] = 6;
		dunju[2] = 3;
		break;
		
	//阴遁
	case JQXiaZhi:
	case JQBaiLu:
		dunju[0] = 9;
		dunju[1] = 3;
		dunju[2] = 6;
		break;
	case JQXiaoShu:
		dunju[0] = 8;
		dunju[1] = 2;
		dunju[2] = 5;
		break;
	case JQQiuFen:
	case JQDaShu:
		dunju[0] = 7;
		dunju[1] = 1;
		dunju[2] = 4;
		break;
	case JQLiQiu:
		dunju[0] = 2;
		dunju[1] = 5;
		dunju[2] = 8;
		break;
	case JQShuangJiang:
	case JQXiaoXue:
		dunju[0] = 5;
		dunju[1] = 8;
		dunju[2] = 2;
		break;
	case JQDaXue:
		dunju[0] = 4;
		dunju[1] = 7;
		dunju[2] = 1;
		break;
	case JQLiDong:
	case JQHanLu:
		dunju[0] = 6;
		dunju[1] = 9;
		dunju[2] = 3;
		break;
	case JQChuShu:
		dunju[0] = 1;
		dunju[1] = 4;
		dunju[2] = 7;
		break;

	default:
		break;
	}
}

void QiMenDunJia::paiJu(int yuan, int xunshou)
{
	//天盘只有一种排法
	for(int i0=0;i0<9;i0++)
	{
		tianPan[i0].qiyi = i0;
		tianPan[i0].star = i0;
		tianPan2[i0] = tianPan[i0]; 
	}
	//人盘只有一种排法
	for(int i0=0;i0<8;i0++)
		renPan[i0] = i0;

	//获得是第几局
	int ju = dunju[yuan % 3];

	//布六仪三奇
	if(isYangDun)
	{
		for(int i=ju; i< ju+9; i++)
		{
			tianPan[BaGua::getPos(i%9)].qiyi= QiYi::getYangDun(i-ju);
		}
	}
	else
	{
		for(int i=ju+9; i>ju; i--)
		{
			tianPan[BaGua::getPos(i%9)].qiyi = QiYi::getYangDun(ju+9-i);
		}
	}

	//排列八诈门盘
	for(int i1=0;i1<8;i1++)
	{	
		isYangDun ? shenPan[i1] = i1 : shenPan[i1] = 8 - i1;
	}

	//根据旬首找值符值使
	for(int i2=0;i2<9;i2++)
	{
		if(tianPan[i2].qiyi == xunshou)
		{
			zhiFu = i2;
			cout<<"值符为"<<JiuXing::getXingName(zhiFu)->c_str()<<endl;
			zhiShi = i2;
			cout<<"值使为"<<BaMen::getBaMenName(zhiShi)->c_str()<<endl;
		}
	}

	//查找用事时辰天干所在的方位
	for(int i3=0;i3<9;i3++)
	{
		if(tianPan[i3].qiyi == shiGan)
		{
			ganPos = i3;
			cout<<"天干所在方位为:"<<BaGua::getGuaName(qiMenDiPan[ganPos])->c_str()<<endl;
		}
	}

	//将zhiFu所在的星转动到ganPos所在位置
	//注意，旋转的时候中五宫是不受影响的，只有八个方向再转
	for(int i4=0;i4<8;i4++)
	{
		tianPan2[(ganPos+i4)%8] = tianPan[(zhiFu + i4) % 8];
		cout<<BaGua::getGuaName(qiMenDiPan[(ganPos+i4)%8])->c_str()<<"\t"<<JiuXing::getXingName((zhiFu + i4) % 8)->c_str()<<endl;
	}

	//求地支所在之宫
	//然后将人盘值使旋转至地支所在之宫
	int diGong = BaGua::getPos(qiMenDiPan[shiGan%9]);
	//cout<<diGong<<"!";
	//cout<<"地支所在之宫为："<<BaGua::getGuaName(diGong)->c_str()<<endl;
	int iZhishi = renPan[zhiShi];
	for(int i5=0,i6=0;i5<9;i5++)
	{
		int iGong = (diGong +i5) % 9;
		if(iGong == 8) continue;
		//cout<<iGong<<"~"<<(iZhishi + i6) % 8<<"~~";
		renPan[iGong] = (iZhishi + i6) % 8;
		i6++;
	}
	//cout<<endl;

	//旋转八诈门盘的神盘，将直符对准天盘九星的值符
	for(int i7=0,i8=0;i7<9;i7++)
	{
		int iGong = (ganPos +i7) % 9;
		if(iGong == 8) continue;
		shenPan2[iGong] = shenPan[i8];
		i8++;
	}
}
