#ifndef ADD_CIRC_ACTION_H
#define ADD_CIRC_ACTION_H
#include "..\Figures\CCircle.h"
#include "Action.h"

//Add Circle Action class
class AddCircAction : public Action
{
private:
	int id;
	Point P1, P2; //Circle Center & point
	GfxInfo CircGfxInfo;
public:
	AddCircAction(ApplicationManager* pApp);

	//Reads Circle parameters
	virtual void ReadActionParameters();

	//Add Circle to the ApplicationManager
	virtual void Execute();
	//Redo & Undo actions
	virtual void Redo();
	virtual void Undo();
};

#endif