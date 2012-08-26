#pragma once

#include <boost/shared_ptr.hpp>
#include <string>
#include <boost/make_shared.hpp>

#include "Gua.h"
#include "Ganzhi.h"

const int yangDun[9] = {TGwu, TGji,TGgeng,TGxin,TGren,TGgui,TGding,TGbing,TGyi}; 
const char qiYiName[10][6] = {"","ÈÕÆæ","ÔÂÆæ","ÐÇÆæ","¼××Ó","¼×Ðç","¼×Éê","¼×Îç","¼×³½","¼×Òú"};

class QiYi
{
public:
	static inline boost::shared_ptr<std::string> getName(int tg)
	{
		return boost::make_shared<std::string>(qiYiName[tg%10]);
	}
	static inline int getYangDun(int i)
	{
		return yangDun[i%9];
	}

};
