#ifndef CHANGE_Draw_COLOR_H
#define CHANGE_Draw_COLOR_H

#include "Action.h"

class ChangeDrawAction : public Action
{
private:
	ActionType Color;            //New CLR
	color C0, C1; int id;        //Undo & Redo parameters
public:
	ChangeDrawAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Redo();
	virtual void Undo();
};

#endif
