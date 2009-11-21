#include "tiangan_gui.h"

TianGan_Gui::TianGan_Gui(void)
{
	this->tgid = TGgui;
}

TianGan_Gui::~TianGan_Gui()
{
}

string TianGan_Gui::getName()
{
	return "¹ï";
}

int TianGan_Gui::getXing()
{
	return this->feature;
}
