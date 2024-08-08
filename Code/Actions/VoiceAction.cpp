#include "VoiceAction.h"
#include "..\ApplicationManager.h"
VoiceAction::VoiceAction(ApplicationManager* pApp) :Action(pApp)
{
}
void VoiceAction::ReadActionParameters()
{
}

void VoiceAction::Execute()
{
	int x, y;
	Output* pOut = pManager->GetOutput();//Get a Pointer to the Output Interfaces 
	Input* pIn = pManager->GetInput();	//Get a Pointer to the Input  Interfaces
	if (pManager->GetVoice())
	{
		pOut->PrintMessage("You have muted the voice, Click anywhere to continue ");
		pIn->GetPointClicked(x, y);
	}
	else
	{
		pOut->PrintMessage("You have enabled the voice, Click anywhere to continue ");
		pIn->GetPointClicked(x, y);
	}
	pManager->SetVoice();
}
