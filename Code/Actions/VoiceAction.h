#pragma once
#include "Action.h"
class VoiceAction : public Action
{
public:
	VoiceAction(ApplicationManager* pApp);
	//Reads  parameters
	virtual void ReadActionParameters();

	virtual void Execute();
};

