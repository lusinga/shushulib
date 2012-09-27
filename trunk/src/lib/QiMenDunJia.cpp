#include "QiMenDunJia.h"
#include "Gua.h"
#include "BaMen.h"
#include "JiuXing.h"
#include "BaZhaShen.h"
#include "QiYi.h"
#include "Tiangan.h"

QiMenDunJia::QiMenDunJia(int jq, int yuan, boost::shared_ptr<Gan_Zhi> pGZ, boost::shared_ptr<Gan_Zhi> pRiGanZhi)
{
	this->jieqi = jq;
	int tg = pGZ->getXunShouTianGan();
	this->zhiGong = pGZ->getOrder() - pGZ->getXunShou();
	cout<<"旬首是："<<Month::buildGan(tg)->getName().c_str()<<endl;
	this->setDunJu();
	shiGan = pGZ->pTG->getTgid();
	shiZhi = pGZ->pDZ->getDzid();
	riGan = pRiGanZhi->pTG->getTgid();
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
	//天盘上的星只有一种排法
	for(int i0=0;i0<9;i0++)
	{
		_tianPan[i0].star = i0;
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

	//将带奇仪的天盘原始排局存起来
	for(int i0=0;i0<9;i0++)
	{
		tianPan[i0] = _tianPan[i0];
	}

	//排列八诈门盘
	for(int i1=0;i1<8;i1++)
	{	
		isYangDun ? _shenPan[i1] = i1 : _shenPan[i1] = 8 - i1;
	}

	//根据旬首找值符值使
	for(int i2=0;i2<9;i2++)
	{
		if(_tianPan[i2].qiyi == xunshou)
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
		if(_tianPan[i3].qiyi == shiGan)
		{
			ganPos = i3;
			cout<<"天干所在方位为:"<<BaGua::getGuaName(qiMenDiPan[ganPos])->c_str()<<endl;
		}
	}

	//将zhiFu所在的星转动到ganPos所在位置
	//注意，旋转的时候中五宫是不受影响的，只有八个方向再转
	for(int i4=0;i4<8;i4++)
	{
		tianPan[(ganPos+i4)%8] = _tianPan[(zhiFu + i4) % 8];
		cout<<BaGua::getGuaName(qiMenDiPan[(ganPos+i4)%8])->c_str()<<"\t"<<JiuXing::getXingName((zhiFu + i4) % 8)->c_str()<<endl;
	}

	//求地支所在之宫
	//通过旬首到占事时的差，即占时干支的order与旬首order之差
	//然后将人盘值使旋转至地支所在之宫

	//先用旬首所在宫与干支差算出地支的宫，然后转成地盘上的方位
	int diGua = (qiMenDiPan[zhiFu] + zhiGong) % 9;
	//cout<<"地支所在之宫为："<<BaGua::getGuaName(diGua)->c_str()<<endl;

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

	//旋转八诈门盘的神盘，将直符对准天盘九星的值符
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
	//吉门偶而合三奇，值此须云百事宜
	for(int i1=0;i1<8;i1++)
	{
		if (BaMen::isJiMen(renPan[i1]) && QiYi::isQi(tianPan[i1].qiyi))
			cout << "吉门偶而合三奇，值此须云百事宜~"<<BaMen::getBaMenName(renPan[i1])->c_str()<<"遇见"<<TianGan::getQiYiName(tianPan[i1].qiyi)->c_str()<<endl;
	}
	//更合从旁加检点，余宫不可有微疵

	//三奇得使诚堪使，六甲遇之非小补
	//乙逢犬马丙鼠猴，六丁玉女骑龙虎

	for(int i2=0;i2<8;i2++)
	{
		//即乙奇加临地盘上甲午(辛)为逢马，加甲戌(己)为逢犬
		//丙奇加甲子(戊)为逢鼠，加甲申(庚)为逢猴
		//丁奇加甲辰(壬)为逢龙，加甲寅(癸)为逢虎
		if((_tianPan[i2].qiyi == TGyi && tianPan[i2].qiyi == TGxin) ||
			(_tianPan[i2].qiyi == TGyi && tianPan[i2].qiyi == TGji) ||
			(_tianPan[i2].qiyi == TGbing && tianPan[i2].qiyi == TGwu) ||
			(_tianPan[i2].qiyi == TGbing && tianPan[i2].qiyi == TGgeng) ||
			(_tianPan[i2].qiyi == TGding && tianPan[i2].qiyi == TGren) ||
			(_tianPan[i2].qiyi == TGding && tianPan[i2].qiyi == TGgui))
		{
			cout<<"三奇得使~天盘"<<TianGan::getQiYiName(_tianPan[i2].qiyi)->c_str()<<"加地盘"<<TianGan::getQiYiName(tianPan[i2].qiyi)->c_str()<<endl;
		}
	}

	//又有三奇游六仪，号为玉女守门扉
	//若遇阴私和合事，诸君但向此中推
	if(tianPan[zhiShi].qiyi == TGding)
		cout<<"玉女守门"<<endl;

	/* 天三门兮地四户，问君此法如何处
	 * 太冲小吉与从魁，此是天门私出路
	 * 地户除危定与开，举事皆从此中去 */

	//天三门求法：以月将加用时顺行，看从魁、小吉、太冲临何位，即是天三门。
	int yuejiang = Month::getYueJiangByJieQi(jieqi);

	int men1 = (shiZhi + (DZmao-yuejiang) + 12) % 12;//求太冲（卯）所临之支
	int men2 = (shiZhi + (DZwei-yuejiang) + 12) % 12;//求小吉（未）所临之支
	int men3 = (shiZhi + (DZyou-yuejiang) + 12) % 12;//求从魁（酉）所临之支

	int hu1 = (shiZhi + 1) % 12;  //除
	int hu2 = (shiZhi + 4) % 12;  //定
	int hu3 = (shiZhi + 7) % 12;  //危
	int hu4 = (shiZhi + 10) % 12; //开

	cout<<"天三门所在支为：";
	cout<<Month::buildZhi(men1)->getName().c_str()<<" ";
	cout<<Month::buildZhi(men2)->getName().c_str()<<" ";
	cout<<Month::buildZhi(men3)->getName().c_str()<<" ";
	cout<<endl;

	cout<<"地四户所在支为：";
	cout<<Month::buildZhi(hu1)->getName().c_str()<<" ";
	cout<<Month::buildZhi(hu2)->getName().c_str()<<" ";
	cout<<Month::buildZhi(hu3)->getName().c_str()<<" ";
	cout<<Month::buildZhi(hu4)->getName().c_str()<<" ";
	cout<<endl;
	
	/*六合太阴太常君，三辰元是地私门
	 * 更得奇门相照耀，出门百事总欣欣*/
	
	//TODO: 这个需要日干

	//太冲天马最为贵，卒然有难能逃避
	//但当乘取天马行，剑戟如山不足畏

	//三为生气五为死，胜在三兮衰在五
	//能识游三避五时，造化真机需记取

	//就中伏吟最为凶，天蓬加著地天蓬
	
	//天蓬若到天英上，须知即是反吟宫

	//八门反复皆如此，生在生门死在死
	//假令吉宿得奇门，万事皆凶不堪使

	//六仪击刑何太凶，甲子直符愁向东
	//xu刑在未申刑虎，寅巳辰辰午刑午 

	//三奇入墓细推寻，甲日哪堪相见未（入坤宫）
	//丙奇属火火墓xu，此时诸事不须为
	//更兼六yi来临二，月奇临六亦同论

	//又有时干入墓宫，课中时下忌相逢
	//wuxu壬辰兼丙xu，gui未丁丑亦同凶

	//五不遇时龙不精，号为日月损光明
	//时干亲克日干上，甲子须知时忌庚

	//奇与门兮共太阴，三般难得总加临
	//若还得二亦为吉，举措行藏必遂心

	//更得直符直使利，兵事用事最为贵
	//常从此地击其冲，百战百胜君须记

	//天yi之神所在宫，大将宜居击对冲
	//假令直符居离九，天英坐取击天蓬

	//甲yi丙丁wu阳时，神居天上要君知
	//坐击须凭天上奇，阴时地下亦如之

	//若见三奇在五阳，偏宜为客自高强
	//忽然逢着五阴位，又宜为主好裁详

	//值符前三六合位，太阴之神在前二
	//后一宫中为九天，后二之神为九地

	//九天之上好扬兵，九地潜藏可立营
	//伏兵但向太阴位，若逢六合利选刑

	//天地人分三遁名，天遁月精华盖临
	//地遁日精紫云蔽，人遁当知是太阴

	//生门六丙合六丁，此为天遁自分明

	//开门六yi合六己，地遁如斯而己矣

	//休门六丁共太阴，欲求人遁无过此

	//要知三遁何所宜，藏形遁迹斯为美

	//庚为太白丙荧惑，庚丙相加谁会得

	//六庚加丙白入荧

	//六丙加庚荧之白

	//白入荧兮贼即发

	//荧入白兮贼须灭

	//丙为勃兮庚为格，格则不通勃乱逆
	//天丙加地庚为勃，天庚加地gui为格

	//丙加天yi为勃符，天yi加丙为飞勃

	//庚加日干为伏干

	//日干加庚飞干格

	//加一宫兮战在野，同一宫兮战于国

	//庚加值符天yi伏

	//值符加庚天yi飞

	//庚加gui兮为大格

	//加己为刑最不宜

	//加壬之时为上格

	//又兼岁月日时逢

	//更有一般奇格者，六庚谨勿加三奇
	//此时若也行兵去，匹马只枪无返期

	//六gui加丁蛇夭娇

	//六丁加gui雀入江

	//六yi加辛龙逃走

	//六辛加yi虎猖狂

	//请观四者是凶神，百事逢之莫措手

	//丙加甲兮鸟跌穴

	//甲加丙兮龙回首

	//只此二者是吉神，为事如意十八九

	//八门若遇开休生，诸事逢之总称情
	//伤宜捕猎终须获，杜好邀遮及隐形

	//景上投书并破阵，惊能擒讼有声名
	//若问死门何所生，只宜凭吊与行刑

	//蓬任冲辅禽阳星，英芮柱心阴宿名
	
	//辅禽心星为上吉，冲任小吉来全亨
	//大凶蓬芮不堪使，小凶英柱不精明

	//大凶无气变为吉，小凶无气一同之

	//吉宿更能逢旺相，万举万全功必成
	//若遇休囚并废没，劝君不必进前程

	//要识九星配五行，各随八卦考羲经
	//坎蓬星水离英火，中宫坤艮土为营
	//乾兑为金震巽木，旺相休囚看重轻

	//与我同仁即为相，我生之月诚为旺
	//废于父母休于财，囚于鬼兮真不妄

	//假令水宿号天蓬，相在初冬与仲冬
	//旺于正二休四五，其余仿此自研穷

	//急则从神缓从门，三五反复天道亨

	//十干加伏若加错，入库休囚吉事危

	//十精为使用为贵，起宫天yi用无遗

	//天目为客地为主，六甲推兮无差理
	//劝君莫失此元机，洞彻九宫扶明主

	//宫制其门不为迫，门制其宫是迫雄

	//天网四张无路走，一二网低有路踪
	//三至四官行入墓，八九离强任西东

	//节气推移时候定，阴阳顺逆要精通
	//三元积数成六纪，天地未成有一理

	//请观歌里精微诀，非是贤人莫传与
}
