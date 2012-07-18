#include "Month.h"

#pragma once
class QiMenDunJia
{
public:
	QiMenDunJia(int jieqi);
	~QiMenDunJia(void);

private:
	int jieqi;
	void setDunJu();
	bool isYangDun;
	int dunju[3];
};

