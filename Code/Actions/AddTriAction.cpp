#include "AddTriAction.h"
#include "..\Figures\CTriangle.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include <Windows.h>
#include "..\Figures\CFigure.h"
AddTriAction::AddTriAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddTriAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();						//Get a Pointer to the Output Interfaces
	Input* pIn = pManager->GetInput();							//Get a Pointer to the Input  Interfaces

	pOut->PrintMessage("New Triangle: Click at The first point");
	pIn->GetPointClicked(P1.x, P1.y);							//Read 1st corner and store in point P1

	pOut->PrintMessage("New Triangle: Click at second corner");
	pIn->GetPointClicked(P2.x, P2.y);							//Read 2nd corner and store in point P2

	pOut->PrintMessage("New Triangle: Click at Third corner");
	pIn->GetPointClicked(P3.x, P3.y);							//Read 3rd corner and store in point P3

	TriGfxInfo.isFilled = isFilled;								//default is not filled

	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();				//get drawin  colors and pen width from the interface
	TriGfxInfo.FillClr = pOut->getCrntFillColor();				//get filling colors and pen width from the interface

	pOut->ClearStatusBar();

}

//Execute the action 
void AddTriAction::Execute()
{
	ReadActionParameters();										//This action needs to read some parameters first
	CTriangle* TRI = new CTriangle(P1, P2, P3, TriGfxInfo);		//Create a Triangle with the parameters read from the user
	if (TRI->IsSahpeValid()&&TRI->area(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y)>100) //check if the shape is valid
	{ 
		if (pManager->GetVoice())
			PlaySound("voice\\Tri", NULL, SND_ASYNC);
		pManager->AddFigure(TRI);								//Add the Triangle to the list of figures is the shape valid
		id = TRI->GetID();
	}
	else
	{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();
		delete TRI;
		pOut->PrintMessage("Invalid points, click to continue..");
		IsExcuted = 0;
		int x, y;
		pIn->GetPointClicked(x, y);
	}
}

void AddTriAction::Redo()									//Creating Shape with same info
{
	CTriangle* TRI = new CTriangle(P1, P2, P3, TriGfxInfo); //Create a Triangle with the parameters read from the user	
	pManager->AddFigure(TRI);								//Add the Triangle to the list of figures is the shape valid
	TRI->SetID(id);
}

void AddTriAction::Undo()									 //Delete the Figure freom the list with keeping its info
{
	CFigure* TRI = pManager->GetFigureById(id);
	if (TRI != NULL) {
		if (TRI->IsSelected())
		{
			TRI->SetSelected(0);
			pManager->SetSelectedfig(NULL);
		}
		pManager->ShifLeft(pManager->GetFigureIndexById(TRI->GetID()));
		delete TRI;
	}
}