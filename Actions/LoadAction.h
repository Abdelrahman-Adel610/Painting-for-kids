#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include <fstream>
#include "../Figures/CFigure.h"
#include "../Figures/CCircle.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CTriangle.h"
using namespace std;

class LoadAction : public Action
{
private:
	string fileName;
	ifstream file;
	string drawClr;
	string figName;
	string fillClr;
	GfxInfo gfx;
	int num;
public:

	LoadAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();

};