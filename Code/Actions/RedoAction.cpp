#include "RedoAction.h"
#include "..\ApplicationManager.h"
RedoAction::RedoAction(ApplicationManager* pApp) :Action(pApp)
{
}
void RedoAction::ReadActionParameters()
{
}

void RedoAction::Execute()
{
	if (pManager->GetLastActionIndex() == pManager->GetUndo_RedoActionsNumber())
	{
		IsExcuted = 0;
		return;
	}
	else
	{
		pManager->GetLastActionToRedo()->Redo();
		pManager->RedoLastAction();
		return;
	}
}
