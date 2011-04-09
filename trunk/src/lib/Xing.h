#pragma once

#include <string>
#include <boost/shared_ptr.hpp>

using namespace std;

class Xing
{
public:
	static const int MU   = 0;
	static const int HUO  = 1;
	static const int TU   = 2;
	static const int JIN  = 3;
	static const int SHUI = 4;

	static const int WANG  = 0; 
	static const int XIANG = 1;
	static const int XIU   = 2;
	static const int QIU   = 3;
	static const int SI    = 4;
	static const int ZHEFU = 5;

	Xing(void);
	~Xing(void);
	bool ke(shared_ptr<Xing> xing);
	// �������ԣ�ֵΪ��ľˮ����֮һ
	int feature;
	static bool sheng(int shenger, int shengee);
	static bool ke(int ker, int kee);
	virtual string getFeature() = 0;
	bool sheng(shared_ptr<Xing> xing);

	inline static string transFeature(int feature)
	{
		string fname[] = {"ľ","��","��","��","ˮ",};
		return fname[feature%5];
	}

	static shared_ptr<Xing> buildXing(int xing);
	static int whichWang(shared_ptr<Xing>* pXings, int numbers);
	static shared_ptr<Xing> whichXingIsWang(shared_ptr<Xing>* pXings, int numbers);
	static int getState(shared_ptr<Xing> pXing, shared_ptr<Xing>* pXings, int numbers);
};
