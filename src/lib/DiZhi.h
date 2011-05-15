#pragma once

#include <string>
#include <iostream>

#include "ganzhi.h"

const int DZzi   = 0;
const int DZchou = 1;
const int DZyin  = 2;
const int DZmao  = 3;
const int DZchen = 4;
const int DZsi   = 5;
const int DZwu   = 6;
const int DZwei  = 7;
const int DZshen = 8;
const int DZyou  = 9;
const int DZxu   = 10;
const int DZhai  = 11;

using namespace std;

class DiZhi : public GanZhi
{
public:


	DiZhi(void);
	virtual ~DiZhi(void);
	static bool he(int he1, int he2);//ÁùºÏ
	static bool sanhe(int he1, int he2, int he3);//ÈýºÏ
	static bool chong(int chong1, int chong2);//³å
	int getDzid(void);

	int getMonth(void);

	bool he(boost::shared_ptr<DiZhi> pz);
	bool chong(boost::shared_ptr<DiZhi> pz);
	bool sanhe(boost::shared_ptr<DiZhi> pz2, boost::shared_ptr<DiZhi> pz3);

	virtual int getXing() = 0;

protected:
	int dzid;
};
