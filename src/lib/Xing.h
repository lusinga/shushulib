#pragma once

#include <string>

using namespace std;

class Xing
{
public:
	static const int JIN  = 0;
	static const int MU   = 1;
	static const int SHUI = 2;
	static const int TU   = 3;
	static const int HUO  = 4;

	Xing(void);
	~Xing(void);
	bool ke(Xing* xing);
	// 基本属性，值为金木水土火之一
	int feature;
	static bool sheng(int shenger, int shengee);
	static bool ke(int ker, int kee);
	virtual string getFeature() = 0;
	bool sheng(Xing* xing);
};
