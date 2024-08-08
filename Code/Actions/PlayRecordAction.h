#ifndef PLAY_RECORD_ACTION_H
#define PLAY_RECORD_ACTION_H
#pragma once
#include "Action.h"
class PlayRecordAction :public Action
{
private:
	string fileName;
public:
	PlayRecordAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();


};
#endif


