#pragma once
#include "Action.h"

class UndoAction : public Action
{
	
public:
	UndoAction(ApplicationManager* pApp);
	//Reads  parameters
	virtual void ReadActionParameters();

	virtual void Execute();
};