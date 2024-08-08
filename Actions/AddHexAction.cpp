#include "AddHexAction.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CFigure.h"
#include "..\ApplicationManager.h"
#include <Windows.h>
#include "..\GUI\input.h"
#include "..\GUI\Output.h"


AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click at the Center");
	//Read the center and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);


	HexGfxInfo.isFilled = isFilled;	//default is not filled
	//get drawing, filling colors and pen width from the interface
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();      
	HexGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
	

}

//Execute the action
void AddHexAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	CHexagon* Hex = new CHexagon(P1, HexGfxInfo);	//Create a Hexagon with the parameters read from the user
	if (Hex->IsSahpeValid())                        //check if the shape is valid
	{
		if (pManager->GetVoice())
			PlaySound("voice\\Hex", NULL, SND_ASYNC);//play sound
		pManager->AddFigure(Hex);					//Add the Hexagon to the list of figures
		id = Hex->GetID();
	}
	else
	{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();
		delete Hex;
		pOut->PrintMessage("Invalid points, click to continue..");
		int x, y;
		IsExcuted = 0;							    //ignore that Action
		pIn->GetPointClicked(x, y);
	}
}
void AddHexAction::Redo()
{
	Output* pOut = pManager->GetOutput();			//Creating Shape with same info
	CHexagon* Hex = new CHexagon(P1, HexGfxInfo);
	pManager->AddFigure(Hex);
	Hex->SetID(id);
}

void AddHexAction::Undo()							//Delete the Figure freom the list with keeping its info
{
	CFigure* Hex = pManager->GetFigureById(id);
	if (Hex != NULL) {
		if (Hex->IsSelected())
		{
			Hex->SetSelected(0);
			pManager->SetSelectedfig(NULL);
		}
		pManager->ShifLeft(pManager->GetFigureIndexById(Hex->GetID()));
		delete Hex;
	}
}