#ifndef CHANGE_FILL_COLOR_H
#define CHANGE_FILL_COLOR_H

#include "Action.h"
#include "..\ApplicationManager.h"

class ChangeFillAction : public Action
{
private:
	ActionType Color;                         //New Fill CLR
	color C0, C1; int id; bool LastStatus;    //Redo and Undo Parameters
public:
	virtual void ReadActionParameters();
	ChangeFillAction(ApplicationManager* pApp);
	virtual void Execute();
	virtual void Redo();
	virtual void Undo();
};

#endif