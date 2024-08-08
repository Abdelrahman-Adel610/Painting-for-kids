#ifndef ADD_TRI_ACTION_H
#define ADD_TRI_ACTION_H
#include "..\Figures\CTriangle.h"
#include "Action.h"
class AddTriAction : public Action
{
private:
	int id;
	Point P1, P2, P3;								//Triangle Corners
	GfxInfo TriGfxInfo;
public:
	AddTriAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();		//Reads Triangle parameters

	virtual void Execute();						//Add Triangle to the ApplicationManager
	virtual void Redo();
	virtual void Undo();
};
#endif





