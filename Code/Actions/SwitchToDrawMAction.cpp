#include "SwitchToDrawMAction.h"
#include "..\ApplicationManager.h"

SwitchToDrawMAction::SwitchToDrawMAction(ApplicationManager* pApp) :Action(pApp)
{
}

void SwitchToDrawMAction::ReadActionParameters()
{
}

void SwitchToDrawMAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int x, y;
	pOut->CreateDrawToolBar();
	pOut->PrintMessage("Welcome back to draw mode ,Click anywhere to continue");
	pIn->GetPointClicked(x, y);
}
