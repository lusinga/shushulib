// SixRen.cpp : Defines the entry point for the console application.
//

#include "Xing.h"
#include "Jin.h"
#include "Shui.h"
#include "Mu.h"
#include "Huo.h"
#include "Tu.h"

#include "month.h"
#include "liuren.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	Xing* xings[5];

	xings[0] = new Jin();
	xings[1] = new Mu();
	xings[2] = new Shui();
	xings[3] = new Tu();
	xings[4] = new Huo();

	for(int i=0;i<5;i++){
		for (int j=0;j<5;j++){
			xings[i]->sheng(xings[j]);
			xings[i]->ke(xings[j]);
		}
	}

	DiZhi* dzs[12];

	for(int i=0;i<12;i++)
	{
		dzs[i] = Month::buildZhi(i);
	}

	for(int i=0;i<12;i++)
	{
		for(int j=0;j<12;j++)
		{
			dzs[i]->he(dzs[j]);
			dzs[i]->chong(dzs[j]);
		}
	}

	LiuRen* plr = new LiuRen(1,3, 0, 0);
	plr->diPan();
	plr->tianPan();
	plr->siKe();

	cin.get();

	return 0;
}
