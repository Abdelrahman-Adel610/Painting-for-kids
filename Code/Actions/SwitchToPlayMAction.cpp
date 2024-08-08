#include "SwitchToPlayMAction.h"
#include "..\ApplicationManager.h"
SwitchToPlayMAction::SwitchToPlayMAction(ApplicationManager* pApp) :Action(pApp)
{
}

void SwitchToPlayMAction::ReadActionParameters()
{
}

void SwitchToPlayMAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	int x, y;
	pOut->CreatePlayToolBar();
	pOut->PrintMessage("Welcome to play mode ,Click anywhere to continue");
	pIn->GetPointClicked(x, y);
}
