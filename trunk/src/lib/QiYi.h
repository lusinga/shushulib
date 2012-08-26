#pragma once

#include <boost/shared_ptr.hpp>
#include <string>
#include <boost/make_shared.hpp>

#include "Gua.h"
#include "Ganzhi.h"

const int yangDun[9] = {TGwu, TGji,TGgeng,TGxin,TGren,TGgui,TGding,TGbing,TGyi}; 
const int yinDun[9] = {TGgui, TGren,TGxin,TGgeng,TGji,TGgeng,TGyi,TGbing,TGding};

class QiYi
{
public:

	static inline int getYangDun(int i)
	{
		return yangDun[i%9];
	}
	static inline int getYinDun(int i)
	{
		return yinDun[i%9];
	}
};
