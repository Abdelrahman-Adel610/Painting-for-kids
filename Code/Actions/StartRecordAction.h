#ifndef START_RECORD_ACTION_H
#define START_RECORD_ACTION_H
#pragma once
#include "Action.h"
#include "../ApplicationManager.h"


class StartRecordAction :public Action
{
private:
	string fileName;
public:
	StartRecordAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();


};
#endif
