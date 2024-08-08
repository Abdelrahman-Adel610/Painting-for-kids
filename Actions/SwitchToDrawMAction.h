#pragma once
#include "Action.h"
class SwitchToDrawMAction :
    public Action
{
public:
	SwitchToDrawMAction(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();

	virtual void Execute();
};

