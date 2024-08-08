#include "ExitAction.h"
#include "..\ApplicationManager.h"
#include <Windows.h>
ExitAction::ExitAction(ApplicationManager* pApp) :Action(pApp)
{
}

void ExitAction::ReadActionParameters()
{
}

void ExitAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int x, y;
	if (pManager->GetVoice())
		PlaySound("voice\\bye", NULL, SND_ASYNC);
	pOut->PrintMessage("See you soon ,Click anywhere to Exit");
	pIn->GetPointClicked(x, y);
	pManager->UnSelect();
	pManager->ResetUndo_RedoActions();
	pManager->ResetRecordList();
	pManager->ClearFigList();
}
