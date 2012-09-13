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
	this->zhiGong = pGZ->getOrder() - pGZ->getXunShou();
	cout<<"Ѯ���ǣ�"<<Month::buildGan(tg)->getName().c_str()<<endl;
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
		cout<<JiuXing::getXingName(tianPan[i].star)->c_str()<<"\t";
		if (i<8) 
		{
			cout<<BaMen::getBaMenName(renPan[i])->c_str()<<"\t";
			cout<<BaZhaShen::getShenName(shenPan[i])->c_str()<<"\t";
		}
		cout<<TianGan::getQiYiName(tianPan[i].qiyi)->c_str()<<"\t";
		cout<<endl;
	}
	duan();
}

void QiMenDunJia::setDunJu()
{
	isYangDun = (this->jieqi < JQXiaZhi && jieqi >= JQDongZhi);

	switch(jieqi)
	{
		//����
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

		//����
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
	//�����ϵ���ֻ��һ���ŷ�
	for(int i0=0;i0<9;i0++)
	{
		_tianPan[i0].star = i0;
	}
	//����ֻ��һ���ŷ�
	for(int i0=0;i0<8;i0++)
		renPan[i0] = i0;

	//����ǵڼ���
	int ju = dunju[yuan % 3];

	//����������
	if(isYangDun)
	{
		for(int i=ju; i< ju+9; i++)
		{
			_tianPan[BaGua::getPos(i%9)].qiyi= QiYi::getYangDun(i-ju);
		}
	}
	else
	{
		for(int i=ju+9; i>ju; i--)
		{
			_tianPan[BaGua::getPos(i%9)].qiyi = QiYi::getYangDun(ju+9-i);
		}
	}

	//�������ǵ�����ԭʼ�žִ�����
	for(int i0=0;i0<9;i0++)
	{
		tianPan[i0] = _tianPan[i0];
	}

	//���а�թ����
	for(int i1=0;i1<8;i1++)
	{	
		isYangDun ? _shenPan[i1] = i1 : _shenPan[i1] = 8 - i1;
	}

	//����Ѯ����ֵ��ֵʹ
	for(int i2=0;i2<9;i2++)
	{
		if(_tianPan[i2].qiyi == xunshou)
		{
			zhiFu = i2;
			cout<<"ֵ��Ϊ"<<JiuXing::getXingName(zhiFu)->c_str()<<endl;
			zhiShi = i2;
			cout<<"ֵʹΪ"<<BaMen::getBaMenName(zhiShi)->c_str()<<endl;
		}
	}

	//��������ʱ��������ڵķ�λ
	for(int i3=0;i3<9;i3++)
	{
		if(_tianPan[i3].qiyi == shiGan)
		{
			ganPos = i3;
			cout<<"������ڷ�λΪ:"<<BaGua::getGuaName(qiMenDiPan[ganPos])->c_str()<<endl;
		}
	}

	//��zhiFu���ڵ���ת����ganPos����λ��
	//ע�⣬��ת��ʱ�����幬�ǲ���Ӱ��ģ�ֻ�а˸�������ת
	for(int i4=0;i4<8;i4++)
	{
		tianPan[(ganPos+i4)%8] = _tianPan[(zhiFu + i4) % 8];
		cout<<BaGua::getGuaName(qiMenDiPan[(ganPos+i4)%8])->c_str()<<"\t"<<JiuXing::getXingName((zhiFu + i4) % 8)->c_str()<<endl;
	}

	//���֧����֮��
	//ͨ��Ѯ�׵�ռ��ʱ�Ĳ��ռʱ��֧��order��Ѯ��order֮��
	//Ȼ������ֵʹ��ת����֧����֮��

	//����Ѯ�����ڹ����֧�������֧�Ĺ���Ȼ��ת�ɵ����ϵķ�λ
	int diGua = (qiMenDiPan[zhiFu] + zhiGong) % 9;
	//cout<<"��֧����֮��Ϊ��"<<BaGua::getGuaName(diGua)->c_str()<<endl;

	int diPos = BaGua::getPos(qiMenDiPan[diGua]);
	//cout<<diGua<<"=="<<diPos<<"!";

	int iZhishi = renPan[zhiShi];
	for(int i5=0,i6=0;i5<9;i5++)
	{
		int iGong = (diPos +i5) % 9;
		if(iGong == 8) continue;
		//cout<<iGong<<"~"<<(iZhishi + i6) % 8<<"~~";
		renPan[iGong] = (iZhishi + i6) % 8;
		i6++;
	}
	//cout<<endl;

	//��ת��թ���̵����̣���ֱ����׼���̾��ǵ�ֵ��
	for(int i7=0,i8=0;i7<9;i7++)
	{
		int iGong = (ganPos +i7) % 9;
		if(iGong == 8) continue;
		shenPan[iGong] = _shenPan[i8];
		i8++;
	}
}

void QiMenDunJia::duan()
{
	//����ż�������棬ֵ�����ư�����
	for(int i1=0;i1<8;i1++)
	{
		if (BaMen::isJiMen(renPan[i1]) && QiYi::isQi(tianPan[i1].qiyi))
			cout << "����ż�������棬ֵ�����ư�����~"<<BaMen::getBaMenName(renPan[i1])->c_str()<<"����"<<TianGan::getQiYiName(tianPan[i1].qiyi)->c_str()<<endl;
	}
	//���ϴ��ԼӼ�㣬�๬������΢��

	//�����ʹ�Ͽ�ʹ��������֮��С��
	//�ҷ�Ȯ�����������Ů������

	for(int i2=0;i2<8;i2++)
	{
		//��������ٵ����ϼ���(��)Ϊ�����Ӽ���(��)Ϊ��Ȯ
		//����Ӽ���(��)Ϊ���󣬼Ӽ���(��)Ϊ���
		//����Ӽ׳�(��)Ϊ�������Ӽ���(��)Ϊ�껢
		if((_tianPan[i2].qiyi == TGyi && tianPan[i2].qiyi == TGxin) ||
			(_tianPan[i2].qiyi == TGyi && tianPan[i2].qiyi == TGji) ||
			(_tianPan[i2].qiyi == TGbing && tianPan[i2].qiyi == TGwu) ||
			(_tianPan[i2].qiyi == TGbing && tianPan[i2].qiyi == TGgeng) ||
			(_tianPan[i2].qiyi == TGding && tianPan[i2].qiyi == TGren) ||
			(_tianPan[i2].qiyi == TGding && tianPan[i2].qiyi == TGgui))
		{
			cout<<"�����ʹ~����"<<TianGan::getQiYiName(_tianPan[i2].qiyi)->c_str()<<"�ӵ���"<<TianGan::getQiYiName(tianPan[i2].qiyi)->c_str()<<endl;
		}
	}
}
