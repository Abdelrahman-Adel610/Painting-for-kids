
#include "..\ApplicationManager.h"
#include "..\Actions\ResetAction.h"

ResetAction::ResetAction(ApplicationManager* pApp) :Action(pApp)
{
}
void ResetAction::ReadActionParameters()
{
}
void ResetAction::Execute()
{
	pManager->ShowAllFigs();
	pManager->UpdateInterface();
}
