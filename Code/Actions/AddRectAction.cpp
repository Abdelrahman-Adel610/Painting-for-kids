#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include <Windows.h>
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddRectAction::ReadActionParameters()
{
															//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");

															//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Rectangle: Click at second corner");

															//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	RectGfxInfo.isFilled = isFilled;						//default is not filled
															//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddRectAction::Execute()
{
														//This action needs to read some parameters first
	ReadActionParameters();

														//Create a rectangle with the parameters read from the user
	CRectangle* REC = new CRectangle(P1, P2, RectGfxInfo);
	if (REC->IsSahpeValid()&& REC->Area()>400)          //check if the shape is valid
	{
		if (pManager->GetVoice())
			PlaySound("voice\\Rect", NULL, SND_ASYNC);	//play sound
		pManager->AddFigure(REC);						//Add the shape to list
		id = REC->GetID();
	}
	else
	{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();
		delete REC;
		pOut->PrintMessage("Invalid points, click to continue..");
		IsExcuted = 0;									//Ignore this action
		int x, y;
		pIn->GetPointClicked(x, y);
	}
}

void AddRectAction::Redo()								//Creating Shape with same info
{
	CRectangle* REC = new CRectangle(P1, P2, RectGfxInfo);
	pManager->AddFigure(REC);
	REC->SetID(id);
}

void AddRectAction::Undo()							//Delete the Figure freom the list with keeping its info
{
	CFigure* REC = pManager->GetFigureById(id);
	if (REC != NULL) {
		if (REC->IsSelected())
		{
			REC->SetSelected(0);
			pManager->SetSelectedfig(NULL);
		}
		pManager->ShifLeft(pManager->GetFigureIndexById(REC->GetID()));
		delete REC;
	}
}
