// SixRen.cpp : Defines the entry point for the console application.
//

#include "Xing.h"
#include "Jin.h"
#include "Shui.h"
#include "Mu.h"
#include "Huo.h"
#include "Tu.h"
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
	
	cin.get();

	return 0;
}
