#pragma once
#include "Action.h"
class SwitchToPlayMAction :
    public Action
{
public:
	SwitchToPlayMAction(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();

	virtual void Execute();
};

