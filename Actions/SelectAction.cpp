#include"SelectAction.h"
#include "..\ApplicationManager.h"
#include "..\Figures\CFigure.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
SelectAction::SelectAction(ApplicationManager* pApp):Action(pApp)
{
}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	pOut->PrintMessage("Select a Figure");

	//Read Point
	pIn->GetPointClicked(P.x, P.y);
}

void SelectAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	if(pManager->belongToShapes(P))
	{ 
	CFigure* fig = pManager->GetFigure(P);
	if (fig != NULL)
	{
		id = fig->GetID();
		if (fig->IsSelected())
		{
			fig->SetSelected(0);
			pManager->SetSelectedfig(NULL);
		}
		else
		{
			fig->SetSelected(1);
			if (pManager->GetSelected())
			{
				pManager->GetSelected()->SetSelected(0);
			}
			pManager->SetSelectedfig(fig);
		}
	}
	}
	else
	{
		IsExcuted = 0;
	}
}

void SelectAction::Redo()
{
	CFigure* fig = pManager->GetFigureById(id);
	if (fig != NULL)
	{
		id = fig->GetID();
		if (fig->IsSelected())
		{
			fig->SetSelected(0);
			pManager->SetSelectedfig(NULL);
		}
		else
		{
			fig->SetSelected(1);
			if (pManager->GetSelected())
			{
				pManager->GetSelected()->SetSelected(0);
			}
			pManager->SetSelectedfig(fig);
		}
	}
}

void SelectAction::Undo()
{
	CFigure* fig = pManager->GetFigureById(id);
	if (fig != NULL)
	{
		id = fig->GetID();
		if (fig->IsSelected())
		{
			fig->SetSelected(0);
			pManager->SetSelectedfig(NULL);
		}
		else
		{
			fig->SetSelected(1);
			if (pManager->GetSelected())
			{
				pManager->GetSelected()->SetSelected(0);
			}
			pManager->SetSelectedfig(fig);
		}
	}
}


