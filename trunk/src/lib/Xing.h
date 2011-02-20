#pragma once

#include <string>

using namespace std;

class Xing
{
public:
	static const int MU   = 0;
	static const int HUO  = 1;
	static const int TU   = 2;
	static const int JIN  = 3;
	static const int SHUI = 4;

	Xing(void);
	~Xing(void);
	bool ke(Xing* xing);
	// �������ԣ�ֵΪ��ľˮ����֮һ
	int feature;
	static bool sheng(int shenger, int shengee);
	static bool ke(int ker, int kee);
	virtual string getFeature() = 0;
	bool sheng(Xing* xing);

	inline static string transFeature(int feature)
	{
		string fname[] = {"ľ","��","��","��","ˮ",};
		return fname[feature%5];
	}

	static int whichWang(Xing** pXing, int numbers);
};
