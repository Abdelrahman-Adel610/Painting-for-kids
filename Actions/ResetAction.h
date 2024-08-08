#ifndef RESET_H
#define RESET_H
#include "../Actions/Action.h"

class ResetAction : public Action
{

public:
	ResetAction(ApplicationManager* pApp);
void	ReadActionParameters();
	virtual void Execute();						

};
#endif


