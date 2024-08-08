#ifndef ADD_RECT_ACTION_H
#define ADD_RECT_ACTION_H
#include "..\Figures\CRectangle.h"
#include "Action.h"

//Add Rectangle Action class
class AddRectAction : public Action
{
private:
	int id;
	Point P1, P2; //Rectangle Corners
	GfxInfo RectGfxInfo;
public:
	AddRectAction(ApplicationManager* pApp);

	//Reads rectangle parameters
	virtual void ReadActionParameters();

	//Add rectangle to the ApplicationManager
	virtual void Execute();
	virtual void Redo();
	virtual void Undo();
};

#endif