#ifndef STOP_RECORD_ACTION_H
#define STOP_RECORD_ACTION_H
#pragma once
#include "Action.h"
#include "../ApplicationManager.h"


class StopRecordAction :public Action
{
private:
	string fileName;
public:
	StopRecordAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();


};
#endif
