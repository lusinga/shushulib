#pragma once

#include <boost/shared_ptr.hpp>
#include <string>
#include <boost/make_shared.hpp>

#include "Gua.h"

const int ZhiFu    = 0;
const int JiuTian  = 1;
const int JiuDi    = 2;
const int ZhuQue   = 3;
const int GouChen  = 4;
const int LiuHe    = 5;
const int LiuYin   = 6;
const int TengShe  = 7;

const char BaZhaShenName[8][6] = {"Ö±·û","¾ÅÌì","¾ÅµØ","ÖìÈ¸","¹´³Â","ÁùºÏ","ÁùÒõ","ÎŸÉß"};

class BaZhaShen
{
public:
	static inline boost::shared_ptr<std::string> getShenName(int men)
	{
		return boost::make_shared<std::string>(BaZhaShenName[men%8]);
	}

};
