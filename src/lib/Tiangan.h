#pragma once

#include "GanZhi.h"

#include "dizhi.h"
#include <boost/shared_ptr.hpp>
#include <string>
#include <boost/make_shared.hpp>

using namespace std;

const int TGjia  = 0;
const int TGyi   = 1;
const int TGbing = 2;
const int TGding = 3;
const int TGwu   = 4;
const int TGji   = 5;
const int TGgeng = 6;
const int TGxin  = 7;
const int TGren  = 8;
const int TGgui  = 9;

const char qiYiName[10][10] = {"","ÈÕÆæ","ÔÂÆæ","ÐÇÆæ","¼××Ó","¼×Ðç","¼×Éê","¼×Îç","¼×³½","¼×Òú"};

class TianGan : public GanZhi
{
public:
	static int JiGong[];

	//int getDzid(void);
	int getTgid(void);
	int getJiGong();
	int getHe();
	static inline boost::shared_ptr<std::string> getQiYiName(int tg)
	{
		return boost::make_shared<std::string>(qiYiName[tg%10]);
	}

protected:
	int tgid;
};
