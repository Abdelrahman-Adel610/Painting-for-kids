#pragma once
#include "Action.h"
#include "../ApplicationManager.h"
#include <fstream>
using namespace std;
class SaveAction :public Action
{
private:
	string filename;
	ofstream out;
public:
	SaveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();


};

