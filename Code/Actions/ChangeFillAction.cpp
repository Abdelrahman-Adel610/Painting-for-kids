#include "ChangeFillAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ChangeFillAction::ChangeFillAction(ApplicationManager* pApp) :Action(pApp)
{

}

void ChangeFillAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->CreateDrawToolBarFill();            //Open FillClr pallet
	pOut->PrintMessage("Changing Fill Color: Plaese Choose Fill color.");
	Color = pIn->GetUserAction();
}

void ChangeFillAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	C0 = pManager->GetSelected()->getFillClr();               //Store the previous Fill CLR in Undo parm
	id = pManager->GetSelected()->GetID();                    //get The Shape underChanging ID
	LastStatus = pManager->GetSelected()->isFilled();
	switch (Color)                                            //Switch the Color Action to UIColor and storing it in Redo parm
	{
	case CHANGE_COLOR_fBLACK:UI.FillColor = BLACK;
		C1 = BLACK;
		pManager->GetSelected()->ChngFillClr(UI.FillColor);
		isFilled = true;
		pOut->CreateDrawToolBar(); break;
	case CHANGE_COLOR_fBLUE:UI.FillColor = BLUE;
		C1 = BLUE;
		pManager->GetSelected()->ChngFillClr(UI.FillColor);
		isFilled = true;
		pOut->CreateDrawToolBar(); break;
	case CHANGE_COLOR_fGREEN:UI.FillColor = GREEN;
		C1 = GREEN;
		pManager->GetSelected()->ChngFillClr(UI.FillColor);
		isFilled = true;
		pOut->CreateDrawToolBar(); break;
	case CHANGE_COLOR_fORANGE:UI.FillColor = ORANGE;
		C1 = ORANGE;
		pManager->GetSelected()->ChngFillClr(UI.FillColor);
		isFilled = true;
		pOut->CreateDrawToolBar(); break;
	case CHANGE_COLOR_fRED:UI.FillColor = RED;
		C1 = RED;
		pManager->GetSelected()->ChngFillClr(UI.FillColor);
		isFilled = true;
		pOut->CreateDrawToolBar(); break;
	case CHANGE_COLOR_fYELLOW:UI.FillColor = YELLOW;
		C1 = YELLOW;
		pManager->GetSelected()->ChngFillClr(UI.FillColor);
		isFilled = true;
		pOut->CreateDrawToolBar(); break;
	default :
		pOut->PrintMessage("Invalid points, click to continue..");
		IsExcuted = 0;
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->CreateDrawToolBar(); break;
	}
	
}

void ChangeFillAction::Redo()
{
	UI.FillColor = C1;
	pManager->GetFigureById(id)->ChngFillClr(UI.FillColor);
	isFilled = true;
}

void ChangeFillAction::Undo()
{
	isFilled = LastStatus;
	if(!isFilled)
	pManager->GetFigureById(id)->ResetFillColoer();
	else
	{
		UI.FillColor = C0;
		pManager->GetFigureById(id)->ChngFillClr(UI.FillColor);
	}
	
}
