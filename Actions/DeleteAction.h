#ifndef DELETE_DELETE_ACTION_H
#define DELETE_DELETE_ACTION_H
#include "Action.h"
#include "..\ApplicationManager.h"
class DeleteAction : public Action
{
private:
	int id;
	CFigure* fig;

public:
	DeleteAction(ApplicationManager* pApp);

	//Reads  parameters
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Redo();
	virtual void Undo();
	~DeleteAction();

};
#endif