#ifndef MOVE_FIGUAR_ACTION_H
#define MOVE_FIGUAR_ACTION_H
#include "Action.h"
#include "..\ApplicationManager.h"
class MoveFiguarAction : public Action
{
private:
	int id;
	Point P0, P1;
public:
	MoveFiguarAction(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();

	virtual void Execute();
	virtual void Redo();
	virtual void Undo();
	~MoveFiguarAction();
};
#endif