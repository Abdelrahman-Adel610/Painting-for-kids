#ifndef ADD_PICK_Shape_Clr_H
#define ADD_PICK_Shape_Clr_H


#include "Action.h"

class PickShapeClrAction:public Action
{
private:
	Point p;
	struct shape
	{
		string mainShape;
		color mainClr;
	}mainShape;
public:
	PickShapeClrAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};

#endif