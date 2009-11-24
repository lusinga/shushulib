#pragma once

class YinYang
{
public:
	static const int YIN  = 0;
	static const int YANG = 1;

	YinYang(void);
	virtual ~YinYang(void);

	bool isYin();
	bool isYang(); 

	static bool isHe(int gan, int zhi);

protected:
	bool yang;
};
