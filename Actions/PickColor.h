#ifndef ADD_PICK_Color_H
#define ADD_PICK_Color_H

#include "Action.h"

//pick Shape Action class
class pickColorAction : public Action
{
private:
	Point p;
	color mainColor;
public:
	pickColorAction(ApplicationManager* pApp);
static string CLRtoSTR(color c);
	virtual void ReadActionParameters();

	virtual void Execute();

};

#endif