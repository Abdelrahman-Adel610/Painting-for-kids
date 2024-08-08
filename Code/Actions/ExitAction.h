#pragma once
#include "Action.h"
class ExitAction :
    public Action
{
public:
	ExitAction(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();

	virtual void Execute();
};

