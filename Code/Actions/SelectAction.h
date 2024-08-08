#ifndef SELECT_ACTION_H
#define SELECT_ACTION_H
#include "Action.h"
#include "../Figures/CFigure.h"
class SelectAction : public Action
{
private:
	Point P;
	int id;
public:
	SelectAction(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Redo();
	virtual void Undo();
	~SelectAction();
};
#endif