#include "AddCircAction.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include <Windows.h>
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircAction::AddCircAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at the center");

	//Read Center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Circle: Click at the point");

	//Read Point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);
	CircGfxInfo.isFilled = isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor(); 
	CircGfxInfo.FillClr = pOut->getCrntFillColor();
	pOut->ClearStatusBar();

}

//Execute the action
void AddCircAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	CCircle* CIRC = new CCircle(P1, P2, CircGfxInfo);	//Create a Circle with the parameters read from the user
	if (CIRC->IsSahpeValid()&& CIRC->Area()>200)		//check if the shape valid
	{
		if (pManager->GetVoice())
			PlaySound("voice\\Circle", NULL, SND_ASYNC);  //play sound
		pManager->AddFigure(CIRC);						//Add the Circle to the list of figures
		id = CIRC->GetID();								 //set the ID
	}
	else
	{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();
		delete CIRC;
		pOut->PrintMessage("Invalid points, click to continue..");
		int x, y;
		IsExcuted = false;					  //to ignore that action
		pIn->GetPointClicked(x, y);
	}
}
void AddCircAction::Redo()						//Creating Shape with same info
{
	CCircle* CIRC = new CCircle(P1, P2, CircGfxInfo);
	Output* pOut = pManager->GetOutput();
	pManager->AddFigure(CIRC);					//Add the Circle to the list of figures
	CIRC->SetID(id);
}

void AddCircAction::Undo()						//Delete the Figure freom the list with keeping its info
{
	CFigure* CIRC = pManager->GetFigureById(id);
	if (CIRC != NULL) {
		if (CIRC->IsSelected())
		{
			CIRC->SetSelected(0);
			pManager->SetSelectedfig(NULL);
		}
		pManager->ShifLeft(pManager->GetFigureIndexById(CIRC->GetID()));
		delete CIRC;
	}
}
