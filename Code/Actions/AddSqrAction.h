#ifndef ADD_SQR_ACTION_H
#define ADD_SQR_ACTION_H
#include "..\Figures\CSquare.h"
#include "Action.h"
class AddSqrAction : public Action
{
private:
	int id;
	Point P1;								//Square center
	GfxInfo SqrGfxInfo;
public:
	AddSqrAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();	//Reads Square parameters

	virtual void Execute();					//Add Square to the ApplicationManager
	virtual void Redo();
	virtual void Undo();
};

#endif


