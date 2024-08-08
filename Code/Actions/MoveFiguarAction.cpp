#include"MoveFiguarAction.h"
#include"SelectAction.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
MoveFiguarAction::MoveFiguarAction(ApplicationManager* pApp) :Action(pApp)
{
}

void MoveFiguarAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	//Read Point
}

void MoveFiguarAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if (pManager->GetSelected() != NULL)
	{
		P0 = pManager->GetSelected()->GetCenter();
		pOut->PrintMessage("Select New Center Point");
		pIn->GetPointClicked(P1.x, P1.y);
		if (pManager->GetSelected()->MoveCenter(P1))
		{
			id = pManager->GetSelected()->GetID();
		}
		else
		{
			pOut->PrintMessage("Invalid points, click to continue..");
			IsExcuted = 0;
			int x, y;
			pIn->GetPointClicked(x, y);
		}
	}


}

void MoveFiguarAction::Redo()
{
	CFigure* figure = pManager->GetFigureById(id);
	figure->MoveCenter(P1);
}

void MoveFiguarAction::Undo()
{
	CFigure* figure = pManager->GetFigureById(id);
	figure->MoveCenter(P0);
}

MoveFiguarAction::~MoveFiguarAction()
{
}


