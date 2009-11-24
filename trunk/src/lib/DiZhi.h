#pragma once

#include <string>
#include <iostream>

#include "ganzhi.h"

using namespace std;

class DiZhi : public GanZhi
{
public:
	static const int DZzi   = 0;
	static const int DZchou = 1;
	static const int DZyin  = 2;
	static const int DZmao  = 3;
	static const int DZchen = 4;
	static const int DZsi   = 5;
	static const int DZwu   = 6;
	static const int DZwei  = 7;
	static const int DZshen = 8;
	static const int DZyou  = 9;
	static const int DZxu   = 10;
	static const int DZhai  = 11;

	DiZhi(void);
	virtual ~DiZhi(void);
	static bool he(int he1, int he2);//ÁùºÏ
	static bool sanhe(int he1, int he2, int he3);//ÈýºÏ
	static bool chong(int chong1, int chong2);//³å
	int getDzid(void);

	bool he(DiZhi* pz);
	bool chong(DiZhi* pz);
	bool sanhe(DiZhi* pz2, DiZhi* pz3);

	virtual int getXing() = 0;
	int ke(DiZhi* pdz);

protected:
	int dzid;
};
