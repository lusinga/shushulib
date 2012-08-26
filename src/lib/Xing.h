#pragma once

#include <string>
#include <boost/shared_ptr.hpp>

using namespace std;
using boost::shared_ptr;

const int MU   = 0;
const int HUO  = 1;
const int TU   = 2;
const int JIN  = 3;
const int SHUI = 4;

const int WANG  = 0; 
const int XIANG = 1;
const int XIU   = 2;
const int QIU   = 3;
const int SI    = 4;
const int ZHEFU = 5;

class Xing
{
public:
	Xing(void);
	~Xing(void);
	bool ke(boost::shared_ptr<Xing> xing);
	// 基本属性，值为金木水土火之一
	int feature;
	static bool sheng(int shenger, int shengee);
	static bool ke(int ker, int kee);
	virtual string getFeature() = 0;
	bool sheng(boost::shared_ptr<Xing> xing);

	inline static string transFeature(int feature)
	{
		string fname[] = {"木","火","土","金","水",};
		return fname[feature%5];
	}

	static boost::shared_ptr<Xing> buildXing(int xing);
	static int whichWang(boost::shared_ptr<Xing>* pXings, int numbers);
	static boost::shared_ptr<Xing> whichXingIsWang(boost::shared_ptr<Xing>* pXings, int numbers);
	static int getState(boost::shared_ptr<Xing> pXing, boost::shared_ptr<Xing>* pXings, int numbers);
};
