#ifndef ADD_PICK_Shape_H
#define ADD_PICK_Shape_H

#include "Action.h"

//pick Shape Action class
class pickShapeAction : public Action
{
private:
	Point p;
	string mainShape;
public:
	pickShapeAction(ApplicationManager* pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

};

#endif