#include "AddSqrAction.h"
#include "..\Figures\CSquare.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CFigure.h"
#include <Windows.h>
AddSqrAction::AddSqrAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSqrAction::ReadActionParameters()
{

	Output* pOut = pManager->GetOutput();							//Get a Pointer to the Output Interfaces 
	Input* pIn = pManager->GetInput();								//Get a Pointer to the Input  Interfaces 

	pOut->PrintMessage("New Square: Click at The Center");
	pIn->GetPointClicked(P1.x, P1.y);								//Read Center and store in point P1

	SqrGfxInfo.isFilled = isFilled;									//default is not filled

	SqrGfxInfo.DrawClr = pOut->getCrntDrawColor();					//get drawing colors and pen width from the interface
	SqrGfxInfo.FillClr = pOut->getCrntFillColor();					//get filling colors and pen width from the interface

	pOut->ClearStatusBar();

}

//Execute the action
void AddSqrAction::Execute()
{

	ReadActionParameters();						       	  //This action needs to read some parameters first
	CSquare* SQRE = new CSquare(P1, SqrGfxInfo);		  //Create a Square with the parameters read from the user if it is valid
	if (SQRE->IsSahpeValid())							  //check if the shape is valid
	{
		if (pManager->GetVoice())
			PlaySound("voice\\Sqre", NULL, SND_ASYNC);	  //play sound
		pManager->AddFigure(SQRE);							//Add the Square to the list of figures if it is not valid
		id = SQRE->GetID();
	}
	else
	{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();
		delete SQRE;
		pOut->PrintMessage("Invalid points, click to continue..");
		IsExcuted = 0;                             //Igonre Action
		int x, y;
		pIn->GetPointClicked(x, y);
	}
}

void AddSqrAction::Redo()							//Creating Shape with same info
{
	CSquare* SQRE = new CSquare(P1, SqrGfxInfo);	//Create a Square with the parameters read from the user if it is valid
	pManager->AddFigure(SQRE);						//Add the Square to the list of figures 
	SQRE->SetID(id);
}

void AddSqrAction::Undo()							//Delete the Figure freom the list with keeping its info
{
	CFigure* SQRE = pManager->GetFigureById(id);
	if (SQRE != NULL) {
		if (SQRE->IsSelected())
		{
			SQRE->SetSelected(0);
			pManager->SetSelectedfig(NULL);
		}
		pManager->ShifLeft(pManager->GetFigureIndexById(SQRE->GetID()));
		delete SQRE;
	}
}