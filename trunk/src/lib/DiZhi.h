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
	static bool he(int he1, int he2);//����
	static bool sanhe(int he1, int he2, int he3);//����
	static bool chong(int chong1, int chong2);//��
	int getDzid(void);

	int getMonth(void);

	bool he(shared_ptr<DiZhi> pz);
	bool chong(shared_ptr<DiZhi> pz);
	bool sanhe(shared_ptr<DiZhi> pz2, shared_ptr<DiZhi> pz3);

	virtual int getXing() = 0;

protected:
	int dzid;
};
