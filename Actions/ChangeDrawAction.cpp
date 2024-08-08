#include "ChangeDrawAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
ChangeDrawAction::ChangeDrawAction(ApplicationManager* pApp):Action(pApp)
{
}

void ChangeDrawAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->CreateDrawToolBarDraw();                                                //Open DrawClr pallet
	pOut->PrintMessage("Changing Drawing Color: Plaese Choose Drawing color.");
	Color = pIn->GetUserAction();                                                 //Get the NewColor
}

void ChangeDrawAction::Execute()
{
	ReadActionParameters();                                                   
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	C0 = pManager->GetSelected()->GetDrawingColor();                              //store the previous color in undo parm
	id = pManager->GetSelected()->GetID();										  //get The Shape underChanging ID
	switch (Color)                                                                //change Color Action to Color and store it in Redo parm
	{
	case CHANGE_COLOR_dBLACK:UI.DrawColor = BLACK;
		C1 = BLACK;
		pManager->GetSelected()->ChngDrawClr(UI.DrawColor);
		pOut->CreateDrawToolBar(); break;
	case CHANGE_COLOR_dBLUE:UI.DrawColor = BLUE;
		C1 = BLUE;
		pManager->GetSelected()->ChngDrawClr(UI.DrawColor);
		pOut->CreateDrawToolBar(); break;
	case CHANGE_COLOR_dGREEN:UI.DrawColor = GREEN;
		C1 = GREEN;
		pManager->GetSelected()->ChngDrawClr(UI.DrawColor);
		pOut->CreateDrawToolBar(); break;
	case CHANGE_COLOR_dORANGE:UI.DrawColor = ORANGE;
		C1 = ORANGE;
		pManager->GetSelected()->ChngDrawClr(UI.DrawColor);
		pOut->CreateDrawToolBar(); break;
	case CHANGE_COLOR_dRED:UI.DrawColor = RED;
		C1 = RED;
		pManager->GetSelected()->ChngDrawClr(UI.DrawColor);
		pOut->CreateDrawToolBar(); break;
	case CHANGE_COLOR_dYELLOW:UI.DrawColor = YELLOW;
		C1 = YELLOW;
		pManager->GetSelected()->ChngDrawClr(UI.DrawColor);
		pOut->CreateDrawToolBar(); break;
    default:
		pOut->PrintMessage("Invalid points, click to continue..");
		IsExcuted = 0;
		int x, y;
		pIn->GetPointClicked(x, y);
		pOut->CreateDrawToolBar(); break;
	}
}

void ChangeDrawAction::Redo()
{
	UI.DrawColor = C1;
	pManager->GetFigureById(id)->ChngDrawClr(UI.DrawColor);
}

void ChangeDrawAction::Undo()
{
	UI.DrawColor = C0;
	pManager->GetFigureById(id)->ChngDrawClr(UI.DrawColor);
}