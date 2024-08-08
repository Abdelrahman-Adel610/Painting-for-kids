#include "UndoAction.h"
#include "..\ApplicationManager.h"

UndoAction::UndoAction(ApplicationManager* pApp) :Action(pApp)
{
}

void UndoAction::ReadActionParameters()
{
}

void UndoAction::Execute()
{
	if (pManager->GetLastActionIndex() == 0)
	{
		IsExcuted = 0;
		return;
	}
	else
	{
		pManager->GetLastActionToUndo()->Undo();
		pManager->UndoLastAction();
	}
}
