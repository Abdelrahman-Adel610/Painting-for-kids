#pragma once
#include "Action.h"

class RedoAction	 :  public Action
{
	
public:
	RedoAction(ApplicationManager* pApp);
	//Reads  parameters
	virtual void ReadActionParameters();

	virtual void Execute();
};

