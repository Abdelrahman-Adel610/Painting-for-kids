#pragma once
#include "Action.h"
class DragToMoveAction :
    public Action
{
private:
	int id;
	Point P0, P1,P2,P3,P4;
public:
	DragToMoveAction(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();

	virtual void Execute();
	virtual void Redo();
	virtual void Undo();
};

