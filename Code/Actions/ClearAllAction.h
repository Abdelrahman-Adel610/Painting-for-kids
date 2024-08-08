#ifndef CLEAR_ALL_ACTION_H
#define CLEAR_ALL_ACTION_H
#include "Action.h"
class ClearAllAction : public Action
{
private:
public:
	ClearAllAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	
};
#endif